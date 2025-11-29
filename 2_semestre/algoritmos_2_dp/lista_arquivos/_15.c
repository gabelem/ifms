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
    
    arq = fopen("PRODUTOS.txt", "wb");
    
    if(arq == NULL)
    {
        printf("Erro ao criar arquivo!\n");
        return 1;
    }
    
    fclose(arq);
    
    printf("Arquivo PRODUTOS.txt criado com sucesso!\n");
    printf("Estrutura: codigo, descricao, preco\n");
    
    return 0;
}
