#include <stdio.h>
#include <string.h>

struct Recebimento {
    int num_doc;
    float valor_doc;
    char data_emissao[11];
    char data_vencimento[11];
    int cod_cli;
};

void recebimentos_acima_valor() {
    float valor_min;
    printf("Digite o valor mínimo: ");
    scanf("%f", &valor_min);

    FILE *clientes_file = fopen("clientes.txt", "r");
    FILE *receb_file = fopen("recebimentos.txt", "r");
    
    if (!clientes_file || !receb_file) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    // Pular cabeçalhos
    char linha[256];
    fgets(linha, sizeof(linha), clientes_file);
    fgets(linha, sizeof(linha), receb_file);

    // Ler clientes para memória
    struct Cliente {
        int cod_cli;
        char nome[50];
    } clientes[100];
    
    int num_clientes = 0;
    
    while (fgets(linha, sizeof(linha), clientes_file)) {
        sscanf(linha, "%d;%[^;]", &clientes[num_clientes].cod_cli, clientes[num_clientes].nome);
        num_clientes++;
    }

    printf("\nRecebimentos acima de R$%.2f:\n", valor_min);
    int total = 0;
    
    while (fgets(linha, sizeof(linha), receb_file) {
        struct Recebimento rec;
        sscanf(linha, "%d;%f;%[^;];%[^;];%d", 
               &rec.num_doc, &rec.valor_doc, 
               rec.data_emissao, rec.data_vencimento, 
               &rec.cod_cli);

        if (rec.valor_doc > valor_min) {
            // Encontrar nome do cliente
            char nome_cliente[50] = "Desconhecido";
            for (int i = 0; i < num_clientes; i++) {
                if (clientes[i].cod_cli == rec.cod_cli) {
                    strcpy(nome_cliente, clientes[i].nome);
                    break;
                }
            }

            printf("Cliente: %s\n", nome_cliente);
            printf("Documento: %d | Valor: R$%.2f\n", rec.num_doc, rec.valor_doc);
            printf("Emissão: %s | Vencimento: %s\n\n", rec.data_emissao, rec.data_vencimento);
            total++;
        }
    }

    printf("Total de recebimentos encontrados: %d\n", total);
    fclose(clientes_file);
    fclose(receb_file);
}
