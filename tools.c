#include <stdio.h>
#include "tools.h"
#include <stdlib.h>


void generate() {
    FILE *file = fopen("numbers", "w");

    if (file == NULL) {
        printf("Something went wrong\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        int randomNumber = (rand() % (10 - 1 + 1)) + 1;
        fprintf(file, "%d\n", randomNumber);
    }

    fclose(file);
}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void loadFromFile(int array[]) {
    FILE *file = fopen("numbers", "r");
    printf("#### Poczatkowa tablica ####\n");
    for (int i = 0; i < SIZE; i++) {
        fscanf(file, "%d", &array[i]);
        printf("%d ", array[i]);
    }
    fclose(file);
    printf("\n");
}

void writeToFile(int array[]) {
    FILE *fileOutput = fopen("outputNumbers", "w");
    for (int i = 0; i < SIZE; i++) {
        fprintf(fileOutput, "%d\n", array[i]);   
    }
    fclose(fileOutput);
}