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
  int Data_EmissaoD, Data_EmissaoM, Data_EmissaoA, Data_VencimentoD, Data_VencimentoM, Data_VencimentoA;
};

int clienteExistente(int procurar_cli)
{
  FILE *procurar = fopen("clientes.txt", "r");

  if(!procurar)
  {
    return 0;
  }

  int cod, fone;
  char nome[200], end[200];

  while(fscanf(procurar, "Cod_Cli: %d, Nome: %199[^,], Endereco: %199[^,], Fone: %d\n", &cod, nome, end, &fone) == 4)
  {
    if(cod == procurar_cli)
    {
      fclose(procurar);
      return 1;
    }
  }

  fclose(procurar);
  return 0;
}

int excluirCR(const char *ArquivoCliente, const char *ArquivoRecebimento , char excCR[255])
{
  FILE *excluir_clientes = fopen("clientes.txt", "r");
  FILE *excluir_recebimentos = fopen("recebimentos.txt", "r");

  FILE *substituir_clientes = fopen("subC.txt", "w");
  FILE *substituir_recebimentos = fopen("subR.txt", "w");

  if(excluir_clientes == NULL || substituir_clientes == NULL || excluir_recebimentos == NULL || substituir_recebimentos == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
  }

  char linha[256];

  while(fgets(linha, sizeof(linha), excluir_clientes) != NULL)
  {
    if(strstr(linha, excCR) == NULL) 
    {
      fputs(linha, substituir_clientes);
    }
  }
  fclose(excluir_clientes);
  fclose(substituir_clientes);

  remove(ArquivoCliente);
  rename("subC.txt", ArquivoCliente);

  while(fgets(linha, sizeof(linha), excluir_recebimentos) != NULL)
  {
    if(strstr(linha, excCR) == NULL) 
    {
      fputs(linha, substituir_recebimentos);
    }
  }
  fclose(excluir_recebimentos);
  fclose(substituir_recebimentos);

  remove(ArquivoRecebimento);
  rename("subR.txt", ArquivoRecebimento);

  printf("\nCliente: %s foi removido dos Clientes/Recebimentos\n\n", excCR);

  return 1;
}


#define BUFFER_SIZE 1024
void editarCliente(const char *ArquivoCliente)
{
  FILE *editarCliente = fopen(ArquivoCliente, "r");
  FILE *editarClienteTemp = fopen("clientesTemp.txt", "w");
  char buffer[BUFFER_SIZE];
  char *ptr_substring;

  char editarNome[255], editarEndereco[255], procurarCliente[255];
  int editarFone;

  printf("Insira o codigo do cliente: ");
  scanf(" %199[^\n]", procurarCliente);


  if(editarCliente == NULL || editarClienteTemp == NULL)
  {
    printf("Erro ao abrir os arquivos.\n");
  }

  while(fgets(buffer, BUFFER_SIZE, editarCliente) != NULL)
  {
    ptr_substring = strstr(buffer, procurarCliente);
    if(ptr_substring != NULL) 
    {
      printf("\n[EDITAR] Cod_CLI: %s\n", procurarCliente);

      printf("Nome: \n");
      scanf(" %199[^\n]", editarNome);

      printf("Endereco: ");
      scanf(" %199[^\n]", editarEndereco);

      printf("Telefone: ");
      scanf("%d", &editarFone);

      fprintf(editarClienteTemp, "Cod_Cli: %s, Nome: %s, Endereco: %s, Fone: %d\n", procurarCliente, editarNome, editarEndereco, editarFone);
    }
    else
    {
      fprintf(editarClienteTemp, "%s", buffer);
    }
  }
  fclose(editarCliente);
  fclose(editarClienteTemp);

  remove(ArquivoCliente);
  rename("clientesTemp.txt", ArquivoCliente);

  printf("Cliente alterado com sucesso :)\n");
}

void editarRecebimento(const char *ArquivoRecebimento)
{
  FILE *editarRecebimento = fopen("recebimentos.txt", "r");
  FILE *editarRecebimentoTemp = fopen("recebimentosTemp.txt", "w");

  if(editarRecebimento == NULL || editarRecebimentoTemp == NULL)
  {
    printf("Erro ao abrir os arquivos.\n");
  }

  char buffer[BUFFER_SIZE];
  char *ptr_substring;

  char procurarNumDoc[255];
  char procurarCli[255];

  int editarCliente; 
  
  char Valor_doc[255];
  int dataEmissaoD, dataEmissaoM, dataEmissaoA, dataVencD, dataVencM, dataVencA;

  printf("Insira o Numero do documento: ");
  scanf("%s", procurarNumDoc);

  printf("Insira o Codigo do cliente: ");
  scanf("%s", procurarCli);


  while(fgets(buffer, BUFFER_SIZE, editarRecebimento) != NULL)
  {
  ptr_substring = strstr(buffer, procurarNumDoc);

    if(ptr_substring != NULL)
    {
  
      ptr_substring = strstr(buffer, procurarCli);

      if(ptr_substring != NULL)
      {
        printf("\nDocumento encontrado.\n");
        printf("\nCliente encontrado.\n");

        printf("\n[EDITAR] Cliente: %s, Num_doc: %s\n", procurarCli, procurarNumDoc);

        printf("Alterar Valor do documento: \n");
        scanf("%s", Valor_doc);

        printf("Alterar DIA MES ANO da data de emissao: \n");
        scanf("%d %d %d", &dataEmissaoD, &dataEmissaoM, &dataEmissaoA);

        printf("Alterar DIA MES ANO da data de vencimento: \n");
        scanf("%d %d %d", &dataVencD, &dataVencM, &dataVencA);

        editarCliente = atoi(procurarCli);

        fprintf(editarRecebimentoTemp, "Num_doc: %s, Valor_doc: %s, Data_Emissao: %d/%d/%d, Data_Vencimento: %d/%d/%d, Cod_Cli: %d\n", procurarNumDoc, Valor_doc, dataEmissaoD, dataEmissaoM, dataEmissaoA, dataVencD, dataVencM, dataVencA, editarCliente);
        
        printf("\nRecebimento alterado com sucesso :)\n");
      }
      else
      {
        fprintf(editarRecebimentoTemp, "%s", buffer);
      }

    }
    else
    {
      fprintf(editarRecebimentoTemp, "%s", buffer);
    }
  }
  fclose(editarRecebimento);
  fclose(editarRecebimentoTemp);
  remove(ArquivoRecebimento);
  rename("recebimentosTemp.txt", ArquivoRecebimento);
}

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

  struct Recebimentos *registrar_recebimento;
  registrar_recebimento = malloc(101 * sizeof(struct Recebimentos));

  if(registrar_cliente == NULL)
  {
    printf("alocacao de memoria falhou\n");
  }

  int selecionar = 4;
  char cliente_exluir[255];
  printf("\n");

  do
  {
    printf("MENU \n");
    printf("1. Cadastrar cliente\n");
    printf("2. Cadastrar recebimento\n");
    printf("3. Excluir cliente\n");
    printf("4. Editar cliente\n");
    printf("5. Editar recebimento.\n");
    printf("0. Sair do programa.\n");
    printf("\n");
    scanf("%d", &selecionar);

    if(selecionar == 1)
    {
      Clientes = fopen("clientes.txt", "a");

      printf("Insira o Codigo do cliente: ");
      scanf("%d", &registrar_cliente[0].Cod_Cli);

      printf("Insira o Nome do cliente: ");
      scanf(" %199[^\n]", registrar_cliente[0].Nome);

      printf("Insira o Endereco do cliente: ");
      scanf(" %199[^\n]", registrar_cliente[0].Endereco);

      printf("Insira o Telefone do cliente: ");
      scanf("%d", &registrar_cliente[0].Fone);

      fprintf(Clientes, "Cod_Cli: %d, Nome: %s, Endereco: %s, Fone: %d\n",registrar_cliente[0].Cod_Cli, registrar_cliente[0].Nome, registrar_cliente[0].Endereco, registrar_cliente[0].Fone);
      
      printf("\nCliente cadastrado com sucesso :)\n\n");
      fclose(Clientes);
    }
    
    if(selecionar == 2)
    {
      Recebimentos = fopen("recebimentos.txt", "a");

      printf("Insira o Numero do documento: ");
      scanf("%d", &registrar_recebimento[0].Num_doc);

      printf("Insira o Valor do documento: ");
      scanf("%d", &registrar_recebimento[0].Valor_doc);

      printf("Insira a Data de Emissao (DIA, MES, ANO): ");
      scanf("%d %d %d", &registrar_recebimento[0].Data_EmissaoD, &registrar_recebimento[0].Data_EmissaoM, &registrar_recebimento[0].Data_EmissaoA);

      printf("Insira a Data de Vencimento (DIA, MES, ANO): ");
      scanf(" %d %d %d", &registrar_recebimento[0].Data_VencimentoD, &registrar_recebimento[0].Data_VencimentoM, &registrar_recebimento[0].Data_VencimentoA);

      printf("Insira o Codigo do Cliente: ");
      scanf("%d", &registrar_recebimento[0].Cod_Cli);
      
      if (clienteExistente(registrar_recebimento[0].Cod_Cli))
      {
      printf("\nCliente %d encontrado!\n\n",
      registrar_recebimento[0].Cod_Cli);
      }
      
      fprintf(Recebimentos, "Num_doc: %d, Valor_doc: %d, Data_Emissao: %d/%d/%d, Data_Vencimento: %d/%d/%d, Cod_Cli: %d\n", registrar_recebimento[0].Num_doc, registrar_recebimento[0].Valor_doc, registrar_recebimento[0].Data_EmissaoD, registrar_recebimento[0].Data_EmissaoM, registrar_recebimento[0].Data_EmissaoA, registrar_recebimento[0].Data_VencimentoD, registrar_recebimento[0].Data_VencimentoM, registrar_recebimento[0].Data_VencimentoA, registrar_recebimento[0].Cod_Cli);
      
      printf("\nRecebimento cadastrado com sucesso :)\n\n");
    
      fclose(Recebimentos);
    }

    if(selecionar == 3)
    {
      printf("Insira o Codigo do cliente que deseja excluir: ");
      scanf(" %199[^\n]", cliente_exluir);

      excluirCR("clientes.txt", "recebimentos.txt", cliente_exluir);
    }

    if(selecionar == 4)
    {
      editarCliente("clientes.txt");
    }

    if(selecionar == 5)
    {
      editarRecebimento("recebimentos.txt");
    }

  }while(selecionar != 0);

  free(registrar_cliente);
  free(registrar_recebimento);
  registrar_cliente = NULL;

  fclose(Clientes);
  fclose(Recebimentos);
  printf("\nMemoria foi desalocada!\n");
}
