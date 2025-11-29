#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    char letra;
    float preco_min, preco_max;
    int encontrou = 0;
    
    printf("\n=== CONSULTA AVANCADA DE PRODUTOS ===\n");
    printf("Digite a letra inicial: ");
    
    scanf(" %c", &letra); 
    letra = toupper(letra);
    
    printf("Digite o preco minimo: R$ ");
    scanf("%f", &preco_min);
    
    printf("Digite o preco maximo: R$ ");
    scanf("%f", &preco_max);
    
    arq = fopen("PRODUTOS.txt", "r");
    
    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    
    printf("\n=== RESULTADOS ===\n");
    printf("Produtos que comecam com '%c' e preco entre R$ %.2f e R$ %.2f\n", 
           letra, preco_min, preco_max);
    printf("%-10s %-50s %-12s\n", "Codigo", "Descricao", "Preco");
    printf("------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "%d %s %f", &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        if(toupper(prod.descricao[0]) == letra && 
            prod.preco >= preco_min && 
            prod.preco <= preco_max)
        {
            encontrou = 1;
            printf("%-10d %-50s R$ %-9.2f\n", 
                   prod.codigo, prod.descricao, prod.preco);
        }
    }
    
    if(!encontrou)
    {
        printf("Nenhum produto encontrado com os criterios informados.\n");
    }
    
    fclose(arq);
    return 0;
}
