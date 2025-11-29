#include <stdio.h>
#include <stdlib.h>

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
    
    printf("\n=== PRODUTOS COM PRECO INFERIOR A R$ 15,00 ===\n");
    printf("%-10s %-50s %-12s\n", "Codigo", "Descricao", "Preco");
    printf("------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "%d %s %f", &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        if(prod.preco < 15.00)
        {
            encontrou = 1;
            printf("%-10d %-50s R$ %-9.2f\n", 
                   prod.codigo, prod.descricao, prod.preco);
        }
    }
    
    if(!encontrou)
    {
        printf("Nenhum produto encontrado com preco inferior a R$ 15,00.\n");
    }
    
    fclose(arq);
    return 0;
}
