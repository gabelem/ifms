#include <stdio.h>

int funcao(int vetor[4], int valor)
  {
  int *preencher;
  preencher = vetor;
  
  for(int i = 0; i < 4; i++)
    {
    *preencher = valor;
    printf("%d ", vetor[i]);
    preencher++;
    }
  
  return 0;
  }
  
int main() 
  {
  int v[4];
  int vl = 2;
  
  funcao(v, vl);
  
  return 0;
  }
