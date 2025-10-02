#include <stdio.h>

int main()
  {
  int array[5];

  int *aponta = array;

  for(int i = 0 ; i < 5; i++)
    {
    printf("Digite o valor para array[%d]: ", i);
    scanf("%d", aponta);
    aponta++;
    }

  for(int j = 0; j < 5; j++)
    {
    printf("%d ", array[j]*2);
    }

  return 0;
  }
