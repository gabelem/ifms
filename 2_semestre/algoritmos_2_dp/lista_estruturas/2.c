#include <stdio.h>
#include <stdlib.h>

struct coordenadas_no_plano
  {
  int x, y;
  };

int main() 
  {
  struct coordenadas_no_plano local1;

  printf("Determine a coordenada x: ");
  scanf("%d", &local1.x);

  printf("\nDetermine a coordenada y: ");
  scanf("%d", &local1.y);

  printf("\nA distancia dos pontos x e y em relacao a origem eh: %d e %d\n", abs(local1.x), abs(local1.y));

  return 0;
  }
