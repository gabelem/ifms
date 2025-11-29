#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[100];
    float preco;
} Produto;

int verificar_codigo_existe(int codigo)
{
    FILE *arq = fopen("PRODUTOS.txt", "r");
    Produto prod;
    
    if(arq == NULL)
    {
        return 0;
    }
    
    while(fscanf(arq, "%d\n%99[^\n]\n%f\n", &prod.codigo, prod.descricao, &prod.preco) == 3)
    {
        if(prod.codigo == codigo)
        {
            fclose(arq);
            return 1;
        }
    }
    
    fclose(arq);
    return 0;
}

int main()
{
    FILE *arq;
    Produto prod;
    char continuar;
    
    do
    {
        printf("\n=== INCLUIR PRODUTO ===\n");
        printf("Codigo: ");
        scanf("%d", &prod.codigo);
        
        if(verificar_codigo_existe(prod.codigo))
        {
            printf("Erro: Ja existe um produto com este codigo!\n");
            printf("Deseja tentar outro codigo? (S/N): ");
            scanf(" %c", &continuar);
            continue;
        }
        
        getchar();
        printf("Descricao: ");
        fgets(prod.descricao, 100, stdin);
        prod.descricao[strcspn(prod.descricao, "\n")] = 0;
        
        printf("Preco: R$ ");
        scanf("%f", &prod.preco);
        
        arq = fopen("PRODUTOS.txt", "a");
        if(arq == NULL)
        {
            printf("Erro ao abrir arquivo!\n");
            return 1;
        }
        
        fprintf(arq, "%d\n%s\n%.2f\n", prod.codigo, prod.descricao, prod.preco);
        fclose(arq);
        
        printf("Produto cadastrado com sucesso!\n");
        
        printf("\nDeseja cadastrar outro produto? (S/N): ");
        scanf(" %c", &continuar);
        
    } while(continuar == 'S' || continuar == 's');
    
    return 0;
}
