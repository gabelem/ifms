#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int valor, int A[valor][valor])
{
  int *B;
  B = (int *) malloc(valor * sizeof(int));

  if(B == NULL)
  {
    printf("alocacao falhou\n");
  }

  for(int linha = 0; linha < valor; linha++)
  {
    int soma = 0;
    for(int coluna = 0; coluna < valor; coluna++)
    {
      soma = soma + A[linha][coluna];
    }
    B[linha] = soma;
  }

  printf("\nSoma: ");
  for(int z = 0; z < valor; z++)
  {
    printf("%d ", B[z]);
  }
  printf("\n");

  free(B);
}

int main()
{
  int N;
  printf("Determine o valor para N: ");
  scanf("%d", &N);

  int matriz[N][N];
  srand(time(NULL));
  for(int j = 0; j < N; j++)
  {
    for(int k = 0; k < N; k++)
    {
      matriz[j][k] = rand() % 50;
    }
  }
  
  printf("matriz gerada na main: ");

  for(int j = 0; j < N; j++)
  {
    for(int k = 0; k < N; k++)
    {
      printf("%d ", matriz[j][k]);
    }
  }

  func(N, matriz);
  return 0;
}
