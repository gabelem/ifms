#include <stdio.h>

int main()

{
    int n, idade;
    int soma_maiores = 0;
    int soma_menores = 0;
    int qtd_menores = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &idade);

        if (idade >= 18) {
            soma_maiores += idade;
        } else {
            soma_menores += idade;
            qtd_menores++;
        }
    }

    printf("Soma maiores: %d\n", soma_maiores);

    if (qtd_menores > 0)
        printf("Media menores: %.2f\n", (float)soma_menores / qtd_menores);
    else
        printf("Media menores: 0\n");

    return 0;
}

