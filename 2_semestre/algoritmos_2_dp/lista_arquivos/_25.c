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
    FILE *arq, *temp;
    Produto prod;
    float preco_min, preco_max, percentual;
    int contador = 0;
    
    printf("\n=== APLICAR DESCONTO EM FAIXA DE PRECOS ===\n");
    printf("Digite o preco minimo: R$ ");
    scanf("%f", &preco_min);
    
    printf("Digite o preco maximo: R$ ");
    scanf("%f", &preco_max);
    
    printf("Digite o percentual de desconto (ex: 10 para 10%%): ");
    scanf("%f", &percentual);
    
    arq = fopen("PRODUTOS.txt", "r");
    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    
    temp = fopen("temp.txt", "w");
    if(temp == NULL)
    {
        printf("Erro ao criar arquivo temporario!\n");
        fclose(arq);
        return 1;
    }
    
    printf("\n=== PRODUTOS COM DESCONTO APLICADO ===\n");
    printf("%-10s %-30s %-12s %-12s %-12s\n", 
           "Codigo", "Descricao", "Preco Ant.", "Desconto", "Preco Novo");
    printf("--------------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "%d %s %f", &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        float preco_antigo = prod.preco;
        
        if(prod.preco >= preco_min && prod.preco <= preco_max)
        {
            float desconto = prod.preco * (percentual / 100.0f);
            prod.preco = prod.preco - desconto;
            
            printf("%-10d %-30s R$ %-9.2f R$ %-9.2f R$ %-9.2f\n",
                   prod.codigo, prod.descricao, preco_antigo, desconto, prod.preco);
            contador++;
        }
        
        fprintf(temp, "%d\n%s\n%.2f\n", prod.codigo, prod.descricao, prod.preco);
    }
    
    fclose(arq);
    fclose(temp);
    
    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    
    printf("\n%d produto(s) atualizado(s) com desconto de %.2f%%!\n", 
           contador, percentual);
    
    return 0;
}
