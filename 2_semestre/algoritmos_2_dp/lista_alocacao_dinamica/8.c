#include <stdio.h>
#include <stdlib.h>

int recebe(int N)
{
  int *ptr;
  int vet[N];
  ptr = (int *) malloc(sizeof(vet[N]));

  printf("vet[%d]\n", N);

  if(ptr == NULL)
  {
    printf("falha na alocacao\n");
  }

  if(N <= 0)
  {
    ptr == NULL;
    printf("o ponteiro eh nulo\n");
  }
  
  free(ptr);
  printf("memoria desalocada com sucesso!\n");
}

int main()
{
  recebe(1);
  return 0;
}
