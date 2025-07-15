#include <stdlib.h>

int* preencherVetor(int N, int valor) {
    if (N <= 0)
        return NULL;
    int* vet = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        vet[i] = valor;
    return vet;
}

