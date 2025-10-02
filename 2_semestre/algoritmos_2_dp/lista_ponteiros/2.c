#include <stdio.h>

int main()
  {
  int a,b;

  printf("Digite o valor para a: ");
  scanf("%d", &a);

  printf("\nDigite o valor para b: ");
  scanf("%d", &b);

  if(&a > &b)
    {
    printf("o maior endereco eh 'a' = %d", a);
    }
    else
    {
    printf("o maior endereco eh 'b' = %d", b);
    }

  return 0;
  }
