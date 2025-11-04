#include <stdio.h>
#include <stdlib.h>

int receba(int N, int preencher)
{
  int *ptr;
  int vet[N];
  ptr = (int *) malloc(sizeof(vet[N]));

  if(ptr == NULL)
  {
    printf("memoria nao foi alocada corretamente.");
  }

  for(int i = 0; i < N; i++)
  {
    vet[i] = preencher;
  }

  for(int j = 0; j < N; j++)
  {
    printf("vet[%d] = %d\n", j, vet[j]);
  }

  free(ptr);
  printf("memoria desalocada com sucesso apos a operacao\n");
  return 0;
}

int main()
{
  receba(4,20);

  return 0;
}
