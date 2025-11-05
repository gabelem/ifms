#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int retornar(int N)
{
  int *ptr;
  int array[N];
  ptr = (int *) malloc(N * sizeof(array[N]));

  if(ptr == NULL)
  {
    printf("a memoria nao foi alocada");
  }

  srand(time(NULL));
  for(int i; i < N; i++)
  {
    array[i] = rand() % N;
  }

  for(int j; j < N; j++)
  {
    printf("vet[%d] = %d\n", j, array[j]);
  }

  free(ptr);
  printf("memoria desalocada com sucesso!\n");

  return 0;
}

int main()
{
  retornar(5);
}
