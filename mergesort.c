#include <stdlib.h>
#include <stdio.h>

void intercala(long ar[], long l, long r, long *comparations, long *swaps){
    long mid = (l + r)/2;
    long tam = r - l + 1;
    long aux[tam];
    long inicio = 0, fim = tam - 1;
    for(long i = 0; i <= mid - l; i++) {
        aux[i] = ar[l + i];
    }
    
    for(long i = r, j = mid - l + 1; i > mid; i--, j++){
        aux[j] = ar[i];
    }

    for(long i = 0; i < tam; i++){
        (*comparations)++;
        (*swaps)++;
        if(aux[inicio] < aux[fim]){
            ar[i+l] = aux[inicio];
            inicio++;
        } else {
            ar[i+l] = aux[fim];
            fim--;
        }
    }
}

void mergesort(long ar[], long left, long right, long *comparations, long *swaps){
    if(right == left){
        return;
    } else {
        long middle = (left + right)/2;
        mergesort(ar, left, middle, comparations, swaps);
        mergesort(ar, middle + 1, right, comparations, swaps);
        intercala(ar, left, right, comparations, swaps);
    }
}