#include <stdio.h>

int main()
  {
  FILE *clientes;
  clientes = fopen("clientes.txt", "w");

  if(clientes == NULL)
    {
    printf("arquivo invalido");
    return 1;
    }
    fprintf(clientes, "Cod_Cli, Nome,Endereco, Fone\n");
    fclose(clientes);

    
  FILE *recebimentos;
  recebimentos = fopen("recebimentos.txt", "w");

  if(recebimentos == NULL)
    {
    printf("arquivo invalido");
    return 1;
    }
    fprintf(recebimentos, "Num_doc, Valor_doc, Data_Emissao, Data_Vencimento, Cod_Cli\n");
    fclose(recebimentos);
  }
