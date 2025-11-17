#include <stdio.h>

int main()

{
    int M[5][5];
    int soma_l4 = 0;
    int soma_c2 = 0;
    int soma_diag = 0;
    int soma_total = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    for (int j = 0; j < 5; j++) {
        soma_l4 += M[3][j];
    }

    for (int i = 0; i < 5; i++) {
        soma_c2 += M[i][1];
    }

    for (int i = 0; i < 5; i++) {
        soma_diag += M[i][i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            soma_total += M[i][j];
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("Soma linha 4: %d\n", soma_l4);
    printf("Soma coluna 2: %d\n", soma_c2);
    printf("Soma diagonal principal: %d\n", soma_diag);
    printf("Soma total: %d\n", soma_total);

    return 0;
}

