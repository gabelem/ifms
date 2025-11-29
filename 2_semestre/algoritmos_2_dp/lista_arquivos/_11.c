#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod_cli;
    char nome[50];
    char endereco[100];
    char fone[20];
} Cliente;

typedef struct
{
    int num_doc;
    float valor_doc;
    char data_emissao[11];
    char data_vencimento[11];
    int cod_cli;
} Recebimento;

char *buscar_nome_cliente(int cod_cli)
{
    static char nome[50];
    FILE *arq = fopen("clientes.txt", "r");
    int cod;
    char endereco[100], fone[20];
    
    strcpy(nome, "Nao encontrado");
    
    if (arq == NULL)
    {
        return nome;
    }
    
    while (fscanf(arq, "Cod_Cli: %d, Nome: %[^,], Endereco: %[^,], Fone: %s\n", 
                  &cod, nome, endereco, fone) == 4)
    {
        if (cod == cod_cli)
        {
            fclose(arq);
            return nome;
        }
    }
    
    strcpy(nome, "Nao encontrado");
    fclose(arq);
    return nome;
}

int main()
{
    FILE *arq;
    Recebimento rec;
    float valor_minimo, valor_maximo, total = 0;
    int encontrou = 0;
    
    printf("\n=== RECEBIMENTOS ENTRE DOIS VALORES ===\n");
    printf("Digite o valor minimo: R$ ");
    scanf("%f", &valor_minimo);
    printf("Digite o valor maximo: R$ ");
    scanf("%f", &valor_maximo);
    
    arq = fopen("recebimentos.txt", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo de recebimentos!\n");
        return 1;
    }
    
    printf("\n%-10s %-25s %-12s %-15s\n", "Num Doc", "Cliente", "Valor", "Vencimento");
    printf("------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "Num_doc: %d, Valor_doc: %f, Data_Emissao: %[^,], Data_Vencimento: %[^,], Cod_Cli: %d\n",
                 &rec.num_doc, &rec.valor_doc, rec.data_emissao, rec.data_vencimento, &rec.cod_cli) == 5)
    {
        if(rec.valor_doc >= valor_minimo && rec.valor_doc <= valor_maximo)
        {
            encontrou = 1;
            char *nome_cliente = buscar_nome_cliente(rec.cod_cli);
            
            printf("%-10d %-25s R$ %-9.2f %-15s\n",
            rec.num_doc, nome_cliente, rec.valor_doc, rec.data_vencimento);
            
            total += rec.valor_doc;
        }
    }
    
    if(encontrou)
    {
        printf("------------------------------------------------------------------------\n");
        printf("Total: R$ %.2f\n", total);
    } else
      {
        printf("Nenhum recebimento encontrado entre estes valores.\n");
      }
    
    fclose(arq);
    return 0;
}
