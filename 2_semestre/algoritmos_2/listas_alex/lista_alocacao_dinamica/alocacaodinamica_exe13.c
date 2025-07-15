#include <stdlib.h>

int** matrizTriangular(int N) {
    int** mat = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        mat[i] = (int*) malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            if (i == j)
                mat[i][j] = 0;
            else if (i < j)
                mat[i][j] = 1;
            else
                mat[i][j] = -1;
        }
    }
    return mat;
}
