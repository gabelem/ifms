#include <stdio.h>

struct distancia_entre 
  {
  int x;
  int y;
  };

int main() 
  {
  struct distancia_entre primeira_coord;
  struct distancia_entre segunda_coord;

  primeira_coord.x = 2;
  primeira_coord.y = 2;

  printf("Insira um valor no formato 'x y' para comparar a distancia entre a coordenada (%d,%d): ", primeira_coord.x, primeira_coord.y);
  scanf("%d %d", &segunda_coord.x, &segunda_coord.y);

  printf("(%d,%d)", (primeira_coord.x-segunda_coord.x), (primeira_coord.y-segunda_coord.y));

  return 0;
  }
