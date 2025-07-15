#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int cod_cli;
    char nome[50];
    char endereco[100];
    char fone[20];
} Cliente;

typedef struct {
    int num_doc;
    float valor_doc;
    char data_emissao[11];
    char data_vencimento[11];
    int cod_cli;
} Recebimento;

int cliente_existe(int codigo) {
    FILE *clientes = fopen("clientes.dat", "rb");
    Cliente c;
    if (!clientes) return 0;

    while (fread(&c, sizeof(Cliente), 1, clientes)) {
        if (c.cod_cli == codigo) {
            fclose(clientes);
            return 1;
        }
    }
    fclose(clientes);
    return 0;
}

int main() {
    FILE *receb = fopen("recebimentos.dat", "ab");
    Recebimento r;

    if (!receb) {
        printf("Erro ao abrir arquivo de recebimentos.\n");
        return 1;
    }

    printf("Código do cliente: ");
    scanf("%d", &r.cod_cli);

    if (!cliente_existe(r.cod_cli)) {
        printf("Cliente não encontrado.\n");
        fclose(receb);
        return 1;
    }

    printf("Número do documento: ");
    scanf("%d", &r.num_doc);
    printf("Valor do documento: ");
    scanf("%f", &r.valor_doc);
    printf("Data de emissão (DD/MM/AAAA): ");
    scanf("%s", r.data_emissao);
    printf("Data de vencimento (DD/MM/AAAA): ");
    scanf("%s", r.data_vencimento);

    fwrite(&r, sizeof(Recebimento), 1, receb);
    printf("Recebimento cadastrado!\n");

    fclose(receb);
    return 0;
}

