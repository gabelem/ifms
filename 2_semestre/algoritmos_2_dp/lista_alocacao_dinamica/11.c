#include <stdio.h>
#include <stdlib.h>

void funcao_matriz(int N)
{
  int **ptr;
  ptr = (int **) malloc(N * sizeof(int *));

  if(ptr == NULL)
  {
    printf("nao foi alocado.\n");
  }
  
  for(int i = 0; i < N; i++)
  {
    ptr[i] = malloc(N * sizeof(int));
  }

  int j = N-1;
  for(int i = N-1; i >= 0; i--)
  {
    ptr[i][j] = 1;
    j--;
  }

  for(int i = 0; i <= N-1; i++)
  {
    for(int j = 0; j <= N-1; j++)
    {
      printf("%d\t", ptr[i][j]);
      if(j == N-1)
      {
        printf("\n");
      }
    }
  }

  for(int m = 0; m <= N-1; m++)
  {
    free(ptr[m]);
  }
  free(ptr);
}

int main()
{
  funcao_matriz(3);
}
