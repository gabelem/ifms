#include <stdio.h>

struct Pessoa {
    char nome[100];
    int idade;
    char endereco[100];
};

int main() {
    struct Pessoa p;

    printf("Digite o nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    getchar(); // Limpar buffer do scanf

    printf("Digite o endereco: ");
    fgets(p.endereco, sizeof(p.endereco), stdin);

    printf("\nNome: %sIdade: %d\nEndereco: %s", p.nome, p.idade, p.endereco);
    return 0;
}

