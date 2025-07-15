#include <stdio.h>

struct Atleta {
    char nome[100];
    char esporte[50];
    int idade;
    float altura;
};

int main() {
    struct Atleta atletas[5];
    int i, mais_velho = 0, mais_alto = 0;

    for (i = 0; i < 5; i++) {
        printf("Nome: ");
        getchar();
        fgets(atletas[i].nome, 100, stdin);
        printf("Esporte: ");
        fgets(atletas[i].esporte, 50, stdin);
        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        printf("Altura: ");
        scanf("%f", &atletas[i].altura);
    }

    for (i = 1; i < 5; i++) {
        if (atletas[i].idade > atletas[mais_velho].idade)
            mais_velho = i;
        if (atletas[i].altura > atletas[mais_alto].altura)
            mais_alto = i;
    }

    printf("\nMais velho: %s", atletas[mais_velho].nome);
    printf("Mais alto: %s", atletas[mais_alto].nome);
    return 0;
}

