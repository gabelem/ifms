#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int d, m ,a;
  printf("Insira sua data de nascimento no formato (dd/mm/aa)");
  scanf("%d %d %d", &d, &m, &a);

  if(d > 31 || m > 12) 
  {
    printf("%d/%d/%d invalido\n", d,m,a);
  }
  else
  {
    printf("%d/%d/%d valido\n", d,m ,a);
  }
  return 0;
}
