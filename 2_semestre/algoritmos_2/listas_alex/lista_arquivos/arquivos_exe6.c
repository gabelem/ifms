#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_doc;
    float valor_doc;
    char data_emissao[11];
    char data_vencimento[11];
    int cod_cli;
} Recebimento;

void alterar_recebimento(int cod_cli, int num_doc) {
    FILE *arquivo = fopen("recebimentos.dat", "rb+");
    Recebimento r;

    if (!arquivo) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (fread(&r, sizeof(Recebimento), 1, arquivo)) {
        if (r.cod_cli == cod_cli && r.num_doc == num_doc) {
            fseek(arquivo, -sizeof(Recebimento), SEEK_CUR);

            printf("Novo valor do documento: ");
            scanf("%f", &r.valor_doc);
            printf("Nova data de emissão: ");
            scanf("%s", r.data_emissao);
            printf("Nova data de vencimento: ");
            scanf("%s", r.data_vencimento);

            fwrite(&r, sizeof(Recebimento), 1, arquivo);
            printf("Recebimento alterado com sucesso.\n");
            fclose(arquivo);
            return;
        }
    }

    printf("Recebimento não encontrado.\n");
    fclose(arquivo);
}

int main() {
    int cod, doc;
    printf("Digite o código do cliente: ");
    scanf("%d", &cod);
    printf("Digite o número do documento: ");
    scanf("%d", &doc);
    alterar_recebimento(cod, doc);
    return 0;
}

