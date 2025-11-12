#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int valor ,int A[valor][valor],int B[valor])
{
  int *c;
  c = (int *) malloc(valor *sizeof(int));

  int guardar_multi = 0;
  int somar = 0;
  int x = 0;
  for(int k = 0; k < valor; k++)
  {
  somar = 0;
    for(int l = 0; l < valor; l++)
    {
      guardar_multi = (A[k][l] * B[l]);
      somar = somar + guardar_multi;
      
      if(l == valor -1)
      {
        c[x] = somar;
        x++;
      }
    }
  }

  for(int w = 0; w < valor; w++)
  {
    printf("[%d]\t", c[w]);
  }
  printf("\n");
  
  free(c);
}

int main()
{

  int N;
  printf("Determine o valor de N: ");
  scanf("%d", &N);


  int matriz[N][N], vetor[N];

  srand(time(NULL));
  for(int i = 0; i < N; i++)
  {
    vetor[i] = rand() % 5;

    for(int j = 0; j < N; j++)
    {
      matriz[i][j] = rand() % 5;
    }
  }

  func(N, matriz, vetor);
  return 0;
}
