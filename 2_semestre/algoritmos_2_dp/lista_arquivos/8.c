#include <stdio.h>
#include <string.h>

void imprimirNomeCliente(char *arquivoCli, char *codCli)
{
  FILE *arquivoCliente = fopen(arquivoCli, "r");
  char armazenarBuffer[256];
  int n_linha = 0;
  char *buscador;

  char textoCod_Cli[256], numCod_Cli[256], textoNome[256], Nome[256];

  if(arquivoCliente == NULL)
  {
    printf("Nao foi possivel abrir o arquivo dos clientes para leitura.\n");
  }

  while(fgets(armazenarBuffer, 256, arquivoCliente) != NULL)
  {
    n_linha++;

    buscador = strstr(armazenarBuffer, codCli);

    if(buscador != NULL)
    {
      sscanf(armazenarBuffer, "%s %s %s %s", textoCod_Cli, numCod_Cli, textoNome, Nome);
      printf("Nome: %s\n", Nome);
    }
  }

  fclose(arquivoCliente);
}

void imprimirRecebimentos(char *arquivoR, char *codCli)
{
  FILE *arquivoRecebimento = fopen("recebimentos.txt", "r");
  char armazenarBuffer[256];


  if(arquivoRecebimento == NULL)
  {
    printf("Erro ao abrir o arquivo dos recebimentos para leitura.\n");
  }

  while(fgets(armazenarBuffer, 256, arquivoRecebimento) != NULL)
  {
    if(strstr(armazenarBuffer, codCli) != NULL)
    {
      printf("%s", armazenarBuffer);
    }
  }
  
  fclose(arquivoRecebimento);
}

int main()
{
  char inserirCodigo[256];
  printf("Insira o codigo do cliente: ");
  scanf("%s", inserirCodigo);

  printf("\n||DADOS DE RECEBIMENTO DO CLIENTE||\n");

  imprimirNomeCliente("clientes.txt", inserirCodigo);
  imprimirRecebimentos("recebimentos.txt", inserirCodigo);

  printf("\n");

  return 0;
}
