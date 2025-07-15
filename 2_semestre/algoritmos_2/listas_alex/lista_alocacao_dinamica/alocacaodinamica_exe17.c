#include <stdlib.h>

int* somaColunas(int** A, int N) {
    int* B = (int*) malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
        B[j] = 0;
        for (int i = 0; i < N; i++)
            B[j] += A[i][j];
    }
    return B;
}

