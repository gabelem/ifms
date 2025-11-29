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
    int codigo_excluir, encontrou = 0;
    
    printf("\n=== EXCLUIR PRODUTO ===\n");
    printf("Digite o codigo do produto a excluir: ");
    scanf("%d", &codigo_excluir);
    
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
    
    while(fscanf(arq, "%d %s %f", &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        if(prod.codigo == codigo_excluir)
        {
            encontrou = 1;
            printf("\nProduto excluido:\n");
            printf("Codigo: %d\n", prod.codigo);
            printf("Descricao: %s\n", prod.descricao);
            printf("Preco: R$ %.2f\n", prod.preco);
        }
        else
        {
            fprintf(temp, "%d\n%s\n%.2f\n", prod.codigo, prod.descricao, prod.preco);
        }
    }
    
    fclose(arq);
    fclose(temp);
    
    if(encontrou)
    {
        remove("PRODUTOS.txt");
        rename("temp.txt", "PRODUTOS.txt");
        printf("\nProduto excluido com sucesso!\n");
    }
    else
    {
        remove("temp.txt");
        printf("\nProduto nao encontrado!\n");
    }
    
    return 0;
}
