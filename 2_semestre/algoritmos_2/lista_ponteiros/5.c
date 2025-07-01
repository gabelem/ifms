#include <stdio.h>

int main()
  {
  int array[5];
  int *ponteiro;

  for(ponteiro = array; ponteiro < array + 5; ponteiro++)
    {
    printf("Digite o valor para a array: ");
    scanf("%d", ponteiro);
    }

  for(ponteiro = array; ponteiro < array + 5; ponteiro++) 
    {
    printf("%d ", (*ponteiro*2));
    }
  printf("\n");
  }
