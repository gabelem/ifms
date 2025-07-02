#include <stdio.h>

void funcao(int vetor[5]) 
  {
  int *ptr = vetor;

  for(int i = 0; i < 5; i++) 
    {
    printf("vetor[%d] = %d\n", i, *ptr);
    ptr++;
    }
  }

int main() 
  {
  int vetor2[5] = {1, 2, 3, 4, 5};
  funcao(vetor2);
  }
