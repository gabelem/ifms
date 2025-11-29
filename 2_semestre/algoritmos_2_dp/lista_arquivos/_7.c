#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
  int cod_cli;
  char nome[50];
  char endereco[100];
  char telefone[20];
} Cliente;

typedef struct
{
  int num_doc;
  float valor_doc;
  char data_emissao[11];
  char data_vencimento[11];
  int cod_cli;
} Recebimento;

int calcularAtraso(char *dataVencimento)
{
  time_t t = time(NULL);
  struct tm hoje = *localtime(&t);
  struct tm vencimento = {0};

  sscanf(dataVencimento, "%d/%d/%d", &vencimento.tm_mday, &vencimento.tm_mon, &vencimento.tm_year);
  vencimento.tm_mon -= 1;
  vencimento.tm_year -= 1900;

  time_t t_hoje = mktime(&hoje);
  time_t t_venc = mktime(&vencimento);

  double diferenca = difftime(t_hoje, t_venc) / (60 * 60 * 24);

  return diferenca > 0 ? (int)diferenca : 0;
}

int compararData(char *data, char *inicio, char *fim)
{
  int d1, m1, a1, d2, m2, a2, d3, m3, a3;

  sscanf(data, "%d/%d/%d", &d1, &m1, &a1);
  sscanf(inicio, "%d/%d/%d", &d2, &m2, &a2);
  sscanf(fim, "%d/%d/%d", &d3, &m3, &a3);

  long valor_data = a1 * 10000 + m1 * 100 + d1;
  long valor_inicio = a2 * 10000 + m2 * 100 + d2;
  long valor_fim = a3 * 10000 + m3 * 100 + d3;

  return (valor_data >= valor_inicio && valor_data <= valor_fim);
}

char *buscarNomeCliente(int cod_cli)
{
  static char nome[50];
  FILE *arquivo = fopen("clientes.txt", "r");
  char linha[200];
  Cliente cli;

  strcpy(nome, "Sem nome");

  if (arquivo == NULL)
  {
    return nome;
  }

  while (fgets(linha, sizeof(linha), arquivo))
  {
    if (sscanf(linha, "Cod_Cli: %d, Nome: %49[^,]", &cli.cod_cli, cli.nome) == 2)
    {
      if (cli.cod_cli == cod_cli)
      {
        strcpy(nome, cli.nome);
        break;
      }
    }
  }
  fclose(arquivo);
  return nome;
}

int main()
{
  FILE *arq;
  Recebimento rec;
  char dataInicio[11], dataFinal[11];
  int encontrou = 0;
  char linha[300];

  printf("\n Insira a data de vencimento (DD/MM/AAAA): \n");
  scanf("%s", dataInicio);
  //printf("Data Final (DD/MM/AAAA): ");
  //scanf("%s", dataFinal);

  arq = fopen("recebimentos.txt", "r");
  if (arq == NULL)
  {
    printf("Erro ao abrir arquivo de recebimento.\n");
    return 1;
  }

  printf("\n%-10s %-25s %-12s %-15s %-12s\n", "Num Doc", "Cliente", "Valor", "Vencimento", "Dias de atraso");
  printf("--------------------------------------------------------------------------------\n");

  while (fgets(linha, sizeof(linha), arq))
  {
    if (sscanf(linha, "Num_doc: %d, Valor_doc: %f, Data_Emissao: %10[^,], Data_Vencimento: %10[^,], Cod_Cli: %d",
               &rec.num_doc, &rec.valor_doc, rec.data_emissao, rec.data_vencimento, &rec.cod_cli) == 5)
    {
      if (compararData(rec.data_vencimento, dataInicio, dataFinal))
      {
        encontrou = 1;
        char *nome_cliente = buscarNomeCliente(rec.cod_cli);
        int dias_atrasados = calcularAtraso(rec.data_vencimento);

        printf("%-10d %-25s R$ %-9.2f %-15s %-12d\n", rec.num_doc, nome_cliente, rec.valor_doc, rec.data_vencimento, dias_atrasados);
      }
    }
  }
  
  if (!encontrou)
  {
    printf("Nao foi encontrado recebimentos vencidos nesse periodo.\n");
  }

  fclose(arq);
  
  return 0;
}
