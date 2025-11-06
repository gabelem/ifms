#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *Clientes;
  Clientes = fopen("clientes.txt", "w");

  int quantidade_clientes;
  printf("Determine a quantidade de clientes que deseja cadastrar: ");
  scanf("%d", &quantidade_clientes);

  int Cod_Cli, Fone;
  char Nome[100], Endereco[100];
  for(int i = 0; i < quantidade_clientes; i++)
  {
    printf("Insira o codigo do cliente: ");
    scanf("%d", &Cod_Cli);

    printf("Insira o telefone do cliente: ");
    scanf("%d", &Fone);

    printf("Insira o nome do cliente: ");
    scanf("%s", &Nome);

    printf("Insira o endereco do cliente: ");
    scanf("%s", &Endereco);

    fprintf(Clientes, "Cod_Cli: %d, Fone: %d, Nome: %s, Endereco: %s\n", Cod_Cli, Fone, Nome, Endereco);
  }
  fclose(Clientes);

  return 0;
}
