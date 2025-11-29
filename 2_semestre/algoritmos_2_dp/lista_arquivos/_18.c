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
    int contador = 0;
    
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
    
    printf("\n=== ALTERANDO PRECOS (AUMENTO DE 15%%) ===\n");
    printf("%-10s %-30s %-12s %-12s\n", "Codigo", "Descricao", "Preco Ant.", "Preco Novo");
    printf("------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "%d\n%99[^\n]\n%f\n",
                 &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        float preco_antigo = prod.preco;
        prod.preco = prod.preco * 1.15;
        
        printf("%-10d %-30s R$ %-9.2f R$ %-9.2f\n",
               prod.codigo, prod.descricao, preco_antigo, prod.preco);
        
        fprintf(temp, "%d\n%s\n%.2f\n", prod.codigo, prod.descricao, prod.preco);
        contador++;
    }
    
    fclose(arq);
    fclose(temp);
    
    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    
    printf("\n%d produto(s) atualizado(s) com sucesso!\n", contador);
    
    return 0;
}

