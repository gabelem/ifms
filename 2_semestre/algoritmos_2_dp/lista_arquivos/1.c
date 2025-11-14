#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Clientes
{
  int Cod_Cli, Fone;
  char Nome[200], Endereco[200]; 
};

struct Recebimentos
{
  int Num_doc, Valor_doc, Cod_Cli;
  char Data_Emissao[11], Data_Vencimento[11];
};

int main()
{
  FILE* Clientes;
  FILE* Recebimentos;
  
  Clientes = fopen("clientes.txt", "r");
  Recebimentos = fopen("recebimentos.txt", "r");
  
  if(Clientes == NULL || Recebimentos == NULL)
  {
  printf("\nAVISO: os arquivos estao vazios..\n");
  }
  
  struct Clientes *registrar_cliente;

  registrar_cliente = malloc(101 * sizeof(struct Clientes));

  if(registrar_cliente == NULL)
  {
    printf("alocacao de memoria falhou\n");
  }

  int selecionar = 3;

  printf("\n");

  do
  {
    printf("MENU \n");
    printf("1. Cadastrar cliente\n");
    printf("2. Cadastrar recebimento\n");
    printf("0. Sair do programa.\n");
    printf("\n");
    scanf("%d", &selecionar);

    if(selecionar == 1)
    {
      Clientes = fopen("clientes.txt", "a");
      
      fprintf(Clientes, "Cod_Cli, Nome, Endereco, Fone\n");
      
      printf("\nCliente cadastrado com sucesso :)\n\n");
      
      fclose(Clientes);
    }
    
    if(selecionar == 2)
    {
    Recebimentos = fopen("recebimentos.txt", "a");
    
    fprintf(Recebimentos, "Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli\n");
      
    printf("\nRecebimento cadastrado com sucesso :)\n\n");
    
    fclose(Recebimentos);
    }

  }while(selecionar != 0);

  free(registrar_cliente);
  registrar_cliente = NULL;
  printf("\nMemoria foi desalocada!\n");
}
