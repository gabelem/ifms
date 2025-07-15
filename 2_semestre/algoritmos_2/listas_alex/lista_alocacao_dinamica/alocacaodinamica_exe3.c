#include <stdio.h>
#include <stdlib.h>

struct Cadastro {
    char nome[100];
    int idade;
    char endereco[200];
};

struct Cadastro* criarCadastro(int N) {
    struct Cadastro* vet = (struct Cadastro*) malloc(N * sizeof(struct Cadastro));
    for (int i = 0; i < N; i++) {
        printf("Cadastro %d\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", vet[i].nome);
        printf("Idade: ");
        scanf("%d", &vet[i].idade);
        printf("Endereço: ");
        scanf(" %[^\n]", vet[i].endereco);
    }
    return vet;
}

