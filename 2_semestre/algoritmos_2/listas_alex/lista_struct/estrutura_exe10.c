#include <stdio.h>
#include <string.h>

struct Atleta {
    char nome[100];
    char esporte[50];
    int idade;
    float altura;
};

void ordenar(struct Atleta atletas[], int n) {
    struct Atleta temp;
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (atletas[i].idade < atletas[j].idade) {
                temp = atletas[i];
                atletas[i] = atletas[j];
                atletas[j] = temp;
            }
}

int main() {
    struct Atleta atletas[5];
    for (int i = 0; i < 5; i++) {
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

    ordenar(atletas, 5);
    printf("\nAtletas em ordem decrescente de idade:\n");
    for (int i = 0; i < 5; i++)
        printf("%sIdade: %d\n", atletas[i].nome, atletas[i].idade);

    return 0;
}

