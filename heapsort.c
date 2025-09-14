#include <stdio.h>

void heapfy(int array[], int size, int index, int *comparations, int *swaps) {
    int left, right, max = array[index], index_max = index;

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

void heapsort(int array[], int size, int *comparations, int *swaps) {
    for (int i = size-1; i >= 0; i--) 
        heapfy(array, size, i, comparations, swaps);

    int aux;
    for (int i = size-1; i > 1; i--) {
        (*swaps)++;
        aux = array[i];
        array[i] = array[0];
        array[0] = aux;
        heapfy(array, i-1, 0, comparations, swaps);
    }
}

int main() {
    int array[] = {2, 3, 5, 1, 9, 0, 7, 10, -1, 14, 6, 4};
    
    int c, s;
    heapsort(array, 12, &c, &s);
    for (int i = 0; i < 12; i++)
        printf("%d ", array[i]);
        printf("| %d %d", c, s);
}