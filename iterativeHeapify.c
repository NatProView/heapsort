#include <stdio.h>
#include <stdlib.h>
#include "tools.h"


void heapify(int array[], int size, int i) {

    int largest;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int isDone = 0;
    int iteracja = 0;

    while (isDone == 0) {
        largest = i;
        if (left < size && array[left] > array[largest]) {
        largest = left;
        printf("largest = left\n");
        }

        if (right < size && array[right] > array[largest]) {
            largest = right;
            printf("largest = right\n");
        }

        if (largest != i) {
            swap(&array[i], &array[largest]);
            printf("array[i] <-> array[largest]\n");

            i = largest;
        } else if (largest == i) {
            printf("Done\n");
            isDone = 1;
        } 
        iteracja ++;
        printf("Iteracja: %d | Left: %d | Right: %d | Largest: %d | i: %d\n", iteracja, left, right, largest, i);
    }
    printf("Iteracje: %d\n", iteracja);



}

void heapsort(int array[], int size) {
    
    for (int j = size/2-1; j >=0; j--) {
        heapify(array, size, j);
    }

    for (int j = size - 1; j > 0; j--) {
        swap(&array[0], &array[j]);
        heapify(array, j, 0);
    }
}


int main() {
    int array[SIZE];

    //laduje liczby z pliku tekstowego
    loadFromFile(array);

    heapsort(array, SIZE);

    printf("#### PO SORTOWANIU ####\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    //zapisuje do pliku tekstowego
    writeToFile(array);

    return 0;
}