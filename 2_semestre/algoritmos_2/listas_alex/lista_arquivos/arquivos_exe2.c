#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod_cli;
    char nome[50];
    char endereco[100];
    char fone[20];
} Cliente;

int main() {
    FILE *clientes = fopen("clientes.dat", "ab");
    Cliente c;

    if (!clientes) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    printf("Código do cliente: ");
    scanf("%d", &c.cod_cli);
    getchar();
    printf("Nome: ");
    fgets(c.nome, sizeof(c.nome), stdin);
    printf("Endereço: ");
    fgets(c.endereco, sizeof(c.endereco), stdin);
    printf("Fone: ");
    fgets(c.fone, sizeof(c.fone), stdin);

    fwrite(&c, sizeof(Cliente), 1, clientes);
    printf("Cliente cadastrado!\n");

    fclose(clientes);
    return 0;
}

