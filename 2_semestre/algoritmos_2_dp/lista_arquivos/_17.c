#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[100];
    float preco;
} Produto;

int main()
{
    FILE *arq;
    Produto prod;
    int encontrou = 0;
    
    arq = fopen("PRODUTOS.txt", "r");
    
    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    
    printf("\n=== PRODUTOS COM PRECO SUPERIOR A R$ 500,00 ===\n");
    printf("%-10s %-50s %-12s\n", "Codigo", "Descricao", "Preco");
    printf("------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "%d", &prod.codigo) == 1)
    {
        fgetc(arq);
        
        if(fgets(prod.descricao, sizeof(prod.descricao), arq) != NULL)
        {
            prod.descricao[strcspn(prod.descricao, "\n")] = '\0';
        }
        
        if(fscanf(arq, "%f", &prod.preco) == 1)
        {
            if(prod.preco > 500.00)
            {
                encontrou = 1;
                printf("%-10d %-50s R$ %-9.2f\n", 
                       prod.codigo, prod.descricao, prod.preco);
            }
        }
    }
    
    if(!encontrou)
    {
        printf("Nenhum produto encontrado com preco superior a R$ 500,00.\n");
    }
    
    fclose(arq);
    return 0;
}
