#include <stdio.h>

void funcao(int vetor[5], int preencher_valor) 
  {
  preencher_valor = 2;
  int *ptr = vetor;

  for(int i = 0; i < 5; i++) 
    {
    *ptr = preencher_valor;
    printf("vetor[%d] = %d\n", i, *ptr);
    ptr++;
    }  
  }

int main() 
  {
  int v[5];
  funcao(v, 2);
  return 0;
  }
