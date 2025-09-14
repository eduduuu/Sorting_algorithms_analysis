#include <stdio.h>

void insertionsort(int array[], int size, int *comparations, int *swaps) {
    int aux;
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            (*comparations)++;
            if (array[j] < array[i]) {
                (*swaps)++;
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                i--;
                break;
            }
        }
    }
}

int main() {
    int array[] = {2, 3, 5, 1, 9, 0, 7, 10, -1, 14, 6, 4};
    
    int c, s;
    insertionsort(array, 12, &c, &s);
    for (int i = 0; i < 12; i++)
        printf("%d ", array[i]);
        printf("| %d %d", c, s);
}