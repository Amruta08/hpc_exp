// gcc -o matrixmul matrixmul.c
// ./matrixmul

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int main() {
    int (*matrix1)[SIZE] = malloc(SIZE * SIZE * sizeof(int));
    int (*matrix2)[SIZE] = malloc(SIZE * SIZE * sizeof(int));
    int (*result)[SIZE] = malloc(SIZE * SIZE * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    clock_t start = clock();

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int sum = 0;
            for (int k = 0; k < SIZE; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %0.3f s\n", cpu_time_used);

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
