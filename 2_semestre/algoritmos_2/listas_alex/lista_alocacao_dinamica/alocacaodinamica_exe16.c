#include <stdlib.h>

int* produtoMatrizVetor(int** A, int* B, int N) {
    int* C = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        C[i] = 0;
        for (int j = 0; j < N; j++)
            C[i] += A[i][j] * B[j];
    }
    return C;
}

