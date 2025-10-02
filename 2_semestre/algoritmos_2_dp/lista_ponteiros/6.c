#include <stdio.h>

int main()
  {
  int inteiro[5];

  for(int i = 0; i < 5; i++)
    {
    printf("Digite o valor para a array inteiro[%d]: ", i);
    scanf("%d", &inteiro[i]);
    }

  for(int j = 0; j < 5; j++)
    {
    if(inteiro[j] % 2 == 0)
      {
      printf("n par: %d endereco: %p\n", inteiro[j],&inteiro[j]);
      }
    }


  return 0;
  }
