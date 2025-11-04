#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int n = 0;

  printf("Determine o tamanho do vetor: ");
  scanf("%d", &n);

  int vet[n];

  int *ptr;
  ptr = (int *)malloc(n * sizeof(int));

  if (ptr == NULL) 
  {
    printf("alocacao falhou.\n");
    return 1;
  }

  int i = 0;
  for(i; i < n; i++)
  {
    printf("Determine o valor para vet[%d] = ", i);
    scanf("%d", &vet[i]);
  }

  puts("\n");

  for(int j = 0; j < n; j++)
  {
    printf("vet[%d] = %d\n", j, vet[j]);
  }

  if (i = n)
  {
  free(ptr);
  printf("\nmemoria liberada\n");
  }

  return 0;
}
