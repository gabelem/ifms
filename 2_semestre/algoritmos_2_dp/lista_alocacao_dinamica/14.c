#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int *A, int *B, int valor)
{
  int *c;
  c = malloc(valor * sizeof(int));

  if(c == NULL)
  {
    printf("alocacao falhou.");
  }

  for(int k = 0; k < valor; k++)
  {
    c[k] = A[k]+B[k];
  }

  for(int j = 0; j < valor; j++)
  {
    printf("%d + %d = %d\n", A[j], B[j],c[j]);
  }

  free(c);
  c = NULL;
}

int main()
{
  
  int N;
  printf("Determine o valor N: ");
  scanf("%d", &N);

  int vetor1[N], vetor2[N];

  srand(time(NULL));
  for(int i = 0; i < N; i++)
  {
    vetor1[i] = rand() % 100;
    vetor2[i] = rand() % 100;
  }

  func(vetor1, vetor2, N);

  return 0;
}
