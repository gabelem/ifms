#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int numero;
    char nome[50];
    float nota1;
    float nota2;
} Aluno;

void criar_arquivo() 
{
    FILE *arq = fopen("alunos.dat", "wb");
    
    if(arq == NULL) 
    {
        printf("Erro ao criar arquivo!\n");
        return;
    }
    
    fclose(arq);
    printf("Arquivo criado com sucesso!\n");
}

void incluir_alunos() 
{
    FILE *arq = fopen("alunos.dat", "ab");
    Aluno aluno;
    char continuar;
    
    if(arq == NULL) 
    {
        printf("Erro! Crie o arquivo primeiro (opcao 1).\n");
        return;
    }
    
    do 
    {
        printf("\n=== INCLUIR ALUNO ===\n");
        printf("Numero: ");
        scanf("%d", &aluno.numero);
        getchar();
        
        printf("Nome: ");
        fgets(aluno.nome, 50, stdin);
        aluno.nome[strcspn(aluno.nome, "\n")] = 0;
        
        printf("Nota 1: ");
        scanf("%f", &aluno.nota1);
        
        printf("Nota 2: ");
        scanf("%f", &aluno.nota2);
        
        fwrite(&aluno, sizeof(Aluno), 1, arq);
        printf("Aluno cadastrado!\n");
        
        printf("\nDeseja continuar? (S/N): ");
        scanf(" %c", &continuar);
        
    } while(continuar == 'S' || continuar == 's');
    
    fclose(arq);
    
    printf("\n=== TODOS OS REGISTROS CADASTRADOS ===\n");
    printf("%-10s %-30s %-8s %-8s %-8s\n", 
           "Numero", "Nome", "Nota1", "Nota2", "Media");
    printf("------------------------------------------------------------------------\n");
    
    arq = fopen("alunos.dat", "rb");
    while(fread(&aluno, sizeof(Aluno), 1, arq)) 
    {
        float media = (aluno.nota1 + aluno.nota2) / 2;
        printf("%-10d %-30s %-8.2f %-8.2f %-8.2f\n",
               aluno.numero, aluno.nome, aluno.nota1, aluno.nota2, media);
    }
    fclose(arq);
}

int main() 
{
    int opcao;
    
    do 
    {
        printf("\n=== MENU ===\n");
        printf("1. Criar\n");
        printf("2. Incluir\n");
        printf("3. Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch(opcao) 
        {
            case 1:
                criar_arquivo();
                break;
            case 2:
                incluir_alunos();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 3);
    
    return 0;
}
