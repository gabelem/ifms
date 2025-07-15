#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int* vet = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("vetor[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);
    return 0;
}

