#include <stdlib.h>

int* somarVetores(int* A, int* B, int N) {
    int* C = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        C[i] = A[i] + B[i];
    return C;
}

