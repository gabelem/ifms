#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod_estilista;
    char nome_estilista[50];
    float salario;
} Estilista;

typedef struct
{
    int cod_roupa;
    char descricao[100];
    int cod_estilista;
    int cod_estacao;
    int ano;
} Roupa;

typedef struct
{
    int cod_estacao;
    char nome_estacao[30];
} Estacao;

void cadastrar_estacao()
{
    FILE *arq = fopen("estacoes.dat", "ab");
    Estacao est;
    
    printf("\n=== CADASTRAR ESTACAO ===\n");
    printf("Codigo da estacao: ");
    scanf("%d", &est.cod_estacao);
    getchar();
    printf("Nome da estacao: ");
    fgets(est.nome_estacao, 30, stdin);
    est.nome_estacao[strcspn(est.nome_estacao, "\n")] = 0;
    
    fwrite(&est, sizeof(Estacao), 1, arq);
    fclose(arq);
    printf("Estacao cadastrada com sucesso!\n");
}

void cadastrar_estilista()
{
    FILE *arq = fopen("estilistas.dat", "ab");
    Estilista esti;
    
    printf("\n=== CADASTRAR ESTILISTA ===\n");
    printf("Codigo do estilista: ");
    scanf("%d", &esti.cod_estilista);
    getchar();
    printf("Nome do estilista: ");
    fgets(esti.nome_estilista, 50, stdin);
    esti.nome_estilista[strcspn(esti.nome_estilista, "\n")] = 0;
    printf("Salario: R$ ");
    scanf("%f", &esti.salario);
    
    fwrite(&esti, sizeof(Estilista), 1, arq);
    fclose(arq);
    printf("Estilista cadastrado com sucesso!\n");
}

int verificar_estilista(int cod)
{
    FILE *arq = fopen("estilistas.dat", "rb");
    Estilista esti;
    
    if(arq == NULL)
    {
    return 0;
    }
    
    while(fread(&esti, sizeof(Estilista), 1, arq))
    {
        if(esti.cod_estilista == cod)
        {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

int verificar_estacao(int cod)
{
    FILE *arq = fopen("estacoes.dat", "rb");
    Estacao est;
    
    if(arq == NULL)
    {
    return 0;
    }
    
    while(fread(&est, sizeof(Estacao), 1, arq))
    {
        if(est.cod_estacao == cod)
        {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

void cadastrar_roupa()
{
    FILE *arq = fopen("roupas.dat", "ab");
    Roupa rou;
    
    printf("\n=== CADASTRAR ROUPA ===\n");
    printf("Codigo da roupa: ");
    scanf("%d", &rou.cod_roupa);
    getchar();
    printf("Descricao da roupa: ");
    fgets(rou.descricao, 100, stdin);
    rou.descricao[strcspn(rou.descricao, "\n")] = 0;
    
    printf("Codigo do estilista: ");
    scanf("%d", &rou.cod_estilista);
    if(!verificar_estilista(rou.cod_estilista))
    {
        printf("Erro: Estilista nao cadastrado!\n");
        fclose(arq);
        return;
    }
    
    printf("Codigo da estacao: ");
    scanf("%d", &rou.cod_estacao);
    if(!verificar_estacao(rou.cod_estacao))
    {
        printf("Erro: Estacao nao cadastrada!\n");
        fclose(arq);
        return;
    }
    
    printf("Ano: ");
    scanf("%d", &rou.ano);
    
    fwrite(&rou, sizeof(Roupa), 1, arq);
    fclose(arq);
    printf("Roupa cadastrada com sucesso!\n");
}

char *buscar_nome_estilista(int cod)
{
    static char nome[50];
    FILE *arq = fopen("estilistas.dat", "rb");
    Estilista esti;
    
    strcpy(nome, "Desconhecido");
    if(arq == NULL) return nome;
    
    while(fread(&esti, sizeof(Estilista), 1, arq))
    {
        if(esti.cod_estilista == cod)
        {
            strcpy(nome, esti.nome_estilista);
            break;
        }
    }
    fclose(arq);
    return nome;
}

void relatorio_roupas_estacao()
{
    FILE *arq = fopen("roupas.dat", "rb");
    Roupa rou;
    int cod_est;
    int encontrou = 0;
    
    printf("\n=== RELATORIO DE ROUPAS POR ESTACAO ===\n");
    printf("Codigo da estacao: ");
    scanf("%d", &cod_est);
    
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return;
    }
    
    printf("\n%-10s %-40s %-25s %-10s\n", 
           "Codigo", "Descricao", "Estilista", "Ano");
    printf("--------------------------------------------------------------------------------\n");
    
    while(fread(&rou, sizeof(Roupa), 1, arq))
    {
        if(rou.cod_estacao == cod_est)
        {
            encontrou = 1;
            char *nome_esti = buscar_nome_estilista(rou.cod_estilista);
            printf("%-10d %-40s %-25s %-10d\n",
                   rou.cod_roupa, rou.descricao, nome_esti, rou.ano);
        }
    }
    
    if(!encontrou)
    {
        printf("Nenhuma roupa encontrada para esta estacao.\n");
    }
    
    fclose(arq);
}

int main()
{
    int opcao;
    
    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar Estacao\n");
        printf("2. Cadastrar Estilista\n");
        printf("3. Cadastrar Roupa\n");
        printf("4. Relatorio de Roupas por Estacao\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1: cadastrar_estacao(); break;
            case 2: cadastrar_estilista(); break;
            case 3: cadastrar_roupa(); break;
            case 4: relatorio_roupas_estacao(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}
