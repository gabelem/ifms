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
    char confirmacao;
    
    printf("\n=== EXCLUIR PRODUTOS COM PRECO SUPERIOR A R$ 200,00 ===\n");
    printf("Tem certeza que deseja excluir todos os produtos com preco > R$ 200,00? (S/N): ");
    scanf(" %c", &confirmacao);
    
    if(confirmacao != 'S' && confirmacao != 's')
    {
        printf("Operacao cancelada!\n");
        return 0;
    }
    
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
    
    printf("\n=== PRODUTOS EXCLUIDOS ===\n");
    printf("%-10s %-50s %-12s\n", "Codigo", "Descricao", "Preco");
    printf("------------------------------------------------------------------------\n");
    
    while(fscanf(arq, "%d %s %f", &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        if(prod.preco > 200.00)
        {
            printf("%-10d %-50s R$ %-9.2f\n", 
                   prod.codigo, prod.descricao, prod.preco);
            contador++;
        }
        else
        {
            fprintf(temp, "%d\n%s\n%.2f\n", prod.codigo, prod.descricao, prod.preco);
        }
    }
    
    fclose(arq);
    fclose(temp);
    
    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    
    printf("\n%d produto(s) excluido(s) com sucesso!\n", contador);
    
    return 0;
}
