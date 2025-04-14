#include <stdio.h>
void calcular_potencia(int x, int z)
  {
  printf("Determine o valor de x: ");
  scanf("%d", &x);

  printf("Determine o valor de z: ");
  scanf("%d", &z);

  int i;
  int x_guarda = x;
  
  for(i=1; i < z; i++)
    {
    x = x * x_guarda;
    }
  printf("%d", x);
  }
