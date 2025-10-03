#include <stdio.h>

int funcao(int vetor[4])
  {
  int *percorrer;
  for(int i = 0; i < 4; i++)
    {
    percorrer = vetor;
    printf("%d\n", vetor[i]);
    percorrer++;
    }
  
  return 0;
  }
  
int main()
  {
  int v[4] = {5,10,15,20};
  
  funcao(v);
  
  return 0;
  }
