#include <stdio.h>

void quicksort(long array[], long left, long right, long *comparations, long *swaps) {
    if (left >= right)
        return;
    long pivot = right;
    long smaller = left, bigger = pivot - 1;

    while (smaller <= bigger) {
        (*comparations)++;
        if (array[smaller] < array[pivot]) {
            smaller++;
            continue;
        }
        else {
            (*swaps)++;
            long aux = array[bigger];
            array[bigger] = array[smaller];
            array[smaller] = aux;
            bigger--;
        }
    }
    long aux = array[pivot];
    array[pivot] = array[smaller];
    array[smaller] = aux;

    quicksort(array, left, smaller - 1, comparations, swaps);
    quicksort(array, smaller + 1, right, comparations, swaps);
}