#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int N;
  printf("valores N da matriz: ");
  scanf("%d", &N);

  int **ptr;
  ptr = (int **) malloc(N * sizeof(int *));

  for(int i = 0; i < N; i++)
  {
    ptr[i] = malloc(N * sizeof(int));
  }

  for(int l = 0 ; l < N; l++)
  {
    for(int m = 0; m < N; m++)
    {
      ptr[l][m] = rand() % 100;
    }
  }

  int k = 0;
  for(int j = 0; j < N; j++)
  {
    ptr[j][k] = 0;
    k++;
  }

  for(int l = 0 ; l < N; l++)
  {
    for(int m = 0; m < N; m++)
    {
      printf("%d\t", ptr[l][m]);

      if(m == N-1)
      {
        printf("\n");
      }
    }
  }

  for(int x = 0; x < N; x++)
  {
    free(ptr[x]);
  }
  free(ptr);
}
