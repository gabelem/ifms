#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("Determine o valor para n: ");
  scanf("%d", &n);

  if(n % 2 == 0) 
  {
    printf("%d eh par\n");
  }
  else
  {
    printf("%d nao eh par\n");
  }

  return 0;
}
