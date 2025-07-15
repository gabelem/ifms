#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Cliente {
    int cod_cli;
    char nome[50];
    char endereco[100];
    char fone[15];
};

struct Recebimento {
    int num_doc;
    float valor_doc;
    char data_emissao[11];
    char data_vencimento[11];
    int cod_cli;
};

void recebimentos_por_periodo() {
    FILE *clientes_file = fopen("clientes.txt", "r");
    FILE *receb_file = fopen("recebimentos.txt", "r");
    
    if (!clientes_file || !receb_file) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    char data_inicio[11], data_fim[11];
    printf("Data inicial (DD/MM/AAAA): ");
    scanf("%s", data_inicio);
    printf("Data final (DD/MM/AAAA): ");
    scanf("%s", data_fim);

    // Pular cabeçalhos
    char linha[256];
    fgets(linha, sizeof(linha), clientes_file);
    fgets(linha, sizeof(linha), receb_file);

    // Ler clientes para memória
    struct Cliente clientes[100];
    int num_clientes = 0;
    
    while (fgets(linha, sizeof(linha), clientes_file)) {
        sscanf(linha, "%d;%[^;];%[^;];%s", 
               &clientes[num_clientes].cod_cli,
               clientes[num_clientes].nome,
               clientes[num_clientes].endereco,
               clientes[num_clientes].fone);
        num_clientes++;
    }

    // Processar recebimentos
    time_t hoje = time(NULL);
    struct tm *hoje_tm = localtime(&hoje);
    int total = 0;

    printf("\nRecebimentos no período:\n");
    
    while (fgets(linha, sizeof(linha), receb_file)) {
        struct Recebimento rec;
        sscanf(linha, "%d;%f;%[^;];%[^;];%d", 
               &rec.num_doc, &rec.valor_doc, 
               rec.data_emissao, rec.data_vencimento, 
               &rec.cod_cli);

        // Verificar se está no período
        if (strcmp(rec.data_vencimento, data_inicio) >= 0 && 
            strcmp(rec.data_vencimento, data_fim) <= 0) {
            
            // Calcular dias em atraso
            struct tm venc_tm = {0};
            sscanf(rec.data_vencimento, "%d/%d/%d", 
                   &venc_tm.tm_mday, &venc_tm.tm_mon, &venc_tm.tm_year);
            venc_tm.tm_mon -= 1;
            venc_tm.tm_year -= 1900;
            time_t venc = mktime(&venc_tm);
            int dias_atraso = (hoje - venc) / (60 * 60 * 24);
            if (dias_atraso < 0) dias_atraso = 0;

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
            printf("Vencimento: %s | Dias em atraso: %d\n\n", rec.data_vencimento, dias_atraso);
            total++;
        }
    }

    printf("Total de recebimentos no período: %d\n", total);
    fclose(clientes_file);
    fclose(receb_file);
}
