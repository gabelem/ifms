#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cod_cli;
    char nome[50];
    char endereco[100];
    char fone[20];
} Cliente;

void alterar_cliente(int codigo) {
    FILE *arquivo = fopen("clientes.dat", "rb+");
    Cliente c;

    if (!arquivo) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (fread(&c, sizeof(Cliente), 1, arquivo)) {
        if (c.cod_cli == codigo) {
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);

            printf("Novo nome: ");
            getchar();
            fgets(c.nome, sizeof(c.nome), stdin);
            printf("Novo endereço: ");
            fgets(c.endereco, sizeof(c.endereco), stdin);
            printf("Novo fone: ");
            fgets(c.fone, sizeof(c.fone), stdin);

            fwrite(&c, sizeof(Cliente), 1, arquivo);
            printf("Cliente alterado com sucesso.\n");
            fclose(arquivo);
            return;
        }
    }

    printf("Cliente não encontrado.\n");
    fclose(arquivo);
}

int main() {
    int cod;
    printf("Digite o código do cliente a alterar: ");
    scanf("%d", &cod);
    alterar_cliente(cod);
    return 0;
}

