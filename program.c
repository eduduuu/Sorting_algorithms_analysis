#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

void heapfy(long array[], long size, long index, long *comparations, long *swaps) {
    long left, right, max = array[index], index_max = index;

    while (1) {
        left = index * 2 + 1;
        right = index * 2 + 2;

        (*comparations)++; 
        if (left < size && array[left] > max) {
           max = array[left];
           index_max = left;
        }
        if (right < size && array[right] > max) {
           max = array[right];
           index_max = right;
        }

        if (index_max == index)
            break;

        (*swaps)++;
        array[index_max] = array[index];
        array[index] = max;
        index = index_max;
        max = array[index]; 
    }
}

void heapsort(long array[], long size, long *comparations, long *swaps) {
    for (long i = size-1; i >= 0; i--) 
        heapfy(array, size, i, comparations, swaps);

    long aux;
    for (long i = size-1; i > 1; i--) {
        (*swaps)++;
        aux = array[i];
        array[i] = array[0];
        array[0] = aux;
        heapfy(array, i-1, 0, comparations, swaps);
    }
}

int main () {
    const long MAX_SIZE = 100000, MIN_SIZE = 1, QTD_SIZE = 10;
    long sizes[MAX_SIZE];
    long qtd_sizes = 0;
    for (long size = MIN_SIZE, i = 0; size <= MAX_SIZE; size += ((double)size+32)/32, i++, qtd_sizes++)
    // for (long size = MIN_SIZE, i = 0; size <= MAX_SIZE; size += 10, i++, qtd_sizes++)
        sizes[i] = size;
    double *matrix = (double*)malloc(sizeof(double)*qtd_sizes*QTD_SIZE*4);

    for (long i = 0; i < qtd_sizes; i++) {
        long size = sizes[i];
        for (long iteration = 0; iteration < QTD_SIZE; iteration++) {
            long *array = (long*)malloc(sizeof(long)*size);
            for (long i = 0; i < size; i++)
                array[i] = rand();

            struct timeval start, end;
            long seconds, useconds;
            long comparations = 0, swaps = 0;
            gettimeofday(&start, NULL);
            
            heapsort(array, size, &comparations, &swaps);

            gettimeofday(&end, NULL);
            seconds = end.tv_sec - start.tv_sec;
            useconds = end.tv_usec - start.tv_usec;
            double execution_time = (seconds*1000.0 + useconds/1000.0);

            matrix[(i*QTD_SIZE+iteration)*4] = execution_time;
            matrix[(i*QTD_SIZE+iteration)*4+1] = (double)size;
            matrix[(i*QTD_SIZE+iteration)*4+2] = comparations;
            matrix[(i*QTD_SIZE+iteration)*4+3] = swaps;
            free(array);
        }
    }
    FILE *alg_analysis = fopen("heap.csv", "w");
    fprintf(alg_analysis, "time,size,comparations,swaps\n");
    for (long i = 0; i < qtd_sizes; i++) {
        for (long iteration = 0; iteration < QTD_SIZE; iteration++) 
            fprintf(alg_analysis, "%lf,%lf,%lf,%lf\n", matrix[(i*QTD_SIZE+iteration)*4], matrix[(i*QTD_SIZE+iteration)*4+1], matrix[(i*QTD_SIZE+iteration)*4+2], matrix[(i*QTD_SIZE+iteration)*4+3]);
    }
    fclose(alg_analysis);
    free(matrix);

    return 0;
}