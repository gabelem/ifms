#include <stdlib.h>

int* alocarVetor(int N) {
    if (N <= 0)
        return NULL;
    return (int*) malloc(N * sizeof(int));
}

