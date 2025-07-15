#include <stdlib.h>

int** matrizDiagonalSecundaria(int N) {
    int** mat = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        mat[i] = (int*) malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            mat[i][j] = (i + j == N - 1) ? 1 : 0;
    }
    return mat;
}
