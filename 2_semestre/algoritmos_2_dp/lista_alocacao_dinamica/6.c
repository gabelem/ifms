#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ler_valor(int **M, int linhas2, int colunas2)
{
  int valor;
  printf("encontrar valor na matriz: ");
  scanf("%d", &valor);

  for(int k = 0; k < linhas2 ; k++ )
  {
    for(int l = 0; l < colunas2; l++)
    {
      printf("matriz[%d][%d] = %d\n", k, l, M[k][l]);
    }
  }

  for(int x = 0; x < linhas2; x++)
  {
    for(int y = 0; y < linhas2; y++)
    {
      if(M[x][y] == valor)
      {
        printf("valor [%d] encontrado\n", valor);
        return 0;
      }
    }
  }
}

int main()
{
  int **ptr;
  int linhas, colunas;
  printf("linhas, colunas: ");
  scanf("%d %d", &linhas, &colunas);
  
  srand(time(NULL));

  ptr = (int **) malloc(linhas * sizeof(int *));

  for(int i = 0; i < linhas; i++)
  {
    ptr[i] = malloc(colunas * sizeof(int));
  }

  for(int w = 0; w < linhas; w++)
  {
    for(int z = 0; z < colunas; z++)
    {
      ptr[w][z] = rand() % 100;
    }
  }

  ler_valor(ptr, linhas, colunas);
  for(int j = 0; j < linhas; j++)
  {
    free(ptr[j]);
  }
  free(ptr);
  printf("memoria desalocada\n");

  return 0;
}
