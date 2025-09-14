#include <stdio.h>

void insertionsort(int array[], int size, int *comparations, int *swaps) {
    int aux;
    for (int i = 1; i < size; i++) {
        aux = array[i];
        for (int j = i-1; j >= 0; j--) {
            (*comparations)++;
            if (aux < array[j]) {
                (*swaps)++;
                array[j+1] = array[j];
            } else {
                array[j+1] = aux;
                break;
            }
            if (j == 0) {
                array[j] = aux;
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