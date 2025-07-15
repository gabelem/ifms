#include <stdlib.h>

int* criarVetor(int N) {
    int* vet = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        vet[i] = i;
    return vet;
}

