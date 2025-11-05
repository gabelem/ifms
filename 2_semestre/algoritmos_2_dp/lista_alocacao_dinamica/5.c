#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int N = 0;

  while(N < 1) 
  {
    printf("Determine um valor para N: ");
    scanf("%d", &N);
  }

  int V[N];

  for(int i = 0; i < N; i++)
  {
    V[i] = rand() % 100 + 2;
    printf("V[%d] = %d\n",i, V[i]);
  }

  int *ptr;
  ptr = (int *) malloc(sizeof(V[N]));

  if(ptr == NULL)
  {
    printf("alocacao falhou!\n");
  }

  if(N > 0)
  {
    free(ptr);
    printf("memoria desalocada com sucesso!\n");
  }

  return 0;
}
