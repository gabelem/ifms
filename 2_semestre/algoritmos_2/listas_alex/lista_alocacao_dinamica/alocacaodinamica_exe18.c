#include <stdlib.h>

int** multiplicarMatrizes(int** A, int linA, int colA, int** B, int linB, int colB) {
    if (colA != linB)
        return NULL;

    int** C = (int**) malloc(linA * sizeof(int*));
    for (int i = 0; i < linA; i++) {
        C[i] = (int*) malloc(colB * sizeof(int));
        for (int j = 0; j < colB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

