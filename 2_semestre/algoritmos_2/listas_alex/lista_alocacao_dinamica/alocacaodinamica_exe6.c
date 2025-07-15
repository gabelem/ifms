#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int lin, int col) {
    int** mat = (int**) malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++)
        mat[i] = (int*) malloc(col * sizeof(int));
    return mat;
}

int buscarValor(int** mat, int lin, int col, int val) {
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            if (mat[i][j] == val)
                return 1;
    return 0;
}

int main() {
    int lin, col;
    printf("Linhas: ");
    scanf("%d", &lin);
    printf("Colunas: ");
    scanf("%d", &col);

    int** matriz = alocarMatriz(lin, col);

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &matriz[i][j]);

    int val;
    printf("Valor a buscar: ");
    scanf("%d", &val);

    printf("Resultado da busca: %d\n", buscarValor(matriz, lin, col, val));

    for (int i = 0; i < lin; i++) free(matriz[i]);
    free(matriz);
    return 0;
}

