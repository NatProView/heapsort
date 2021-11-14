#include <stdio.h>
#include "tools.h"


void heapify(int array[], int size, int i);

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

    generate();

    int array[SIZE];

    //laduje liczby z pliku tekstowego
    loadFromFile(array);

    
    heapsort(array, SIZE);

    //wyswietl tablice po heapify
    printf("#### PO SORTOWANIU ####\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    //zapisuje do pliku tekstowego
    writeToFile(array);

    return 0;
}

void heapify(int array[], int size, int i) {
    int largest = i;

    //indeksujemy od 0
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  
    if (left < size && array[left] > array[largest]) {
        largest = left;

    }
    if (right < size && array[right] > array[largest]) {
        largest = right;
        printf("largest = right\n");
    }
    if (largest != i) {
        
        swap(&array[i], &array[largest]);
        printf("array[i] <-> array[largest]\n");

        heapify(array, size, largest);
    }
}

