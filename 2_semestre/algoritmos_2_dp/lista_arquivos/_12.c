#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod_estilista;
    char nome_estilista[50];
    float salario;
} Estilista;

typedef struct
{
    int cod_roupa;
    char descricao[100];
    int cod_estilista;
    int cod_estacao;
    int ano;
} Roupa;

typedef struct
{
    int cod_estacao;
    char nome_estacao[30];
} Estacao;

int main()
{
    FILE *arq_estilista, *arq_roupa, *arq_estacao;
    
    arq_estilista = fopen("estilistas.txt", "wb");
    if(arq_estilista == NULL)
    {
        printf("Erro ao criar arquivo de estilistas!\n");
        return 1;
    }
    fclose(arq_estilista);
    printf("Arquivo 'estilistas.txt' criado com sucesso!\n");
    
    arq_roupa = fopen("roupas.txt", "wb");
    if(arq_roupa == NULL)
    {
        printf("Erro ao criar arquivo de roupas!\n");
        return 1;
    }
    fclose(arq_roupa);
    printf("Arquivo 'roupas.txt' criado com sucesso!\n");
    
    arq_estacao = fopen("estacoes.txt", "wb");
    if(arq_estacao == NULL)
    {
        printf("Erro ao criar arquivo de estacoes!\n");
        return 1;
    }
    fclose(arq_estacao);
    printf("Arquivo 'estacoes.txt' criado com sucesso!\n");
    
    printf("\nTodos os arquivos foram criados com sucesso!\n");
    printf("\nEstrutura dos arquivos:\n");
    printf("- estilistas.txt: codigo, nome, salario\n");
    printf("- roupas.txt: codigo, descricao, cod_estilista, cod_estacao, ano\n");
    printf("- estacoes.txt: codigo, nome_estacao\n");
    
    return 0;
}
