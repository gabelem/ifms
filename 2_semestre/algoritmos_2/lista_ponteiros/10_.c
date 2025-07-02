#include <stdio.h>

int main() 
  {
  int a, *b, **c, ***d;

  printf("Determine o valor a: ");
  scanf("%d", &a);

  b = &a;
  c = &b;
  d = &c;

  int dobro, triplo, quadruplo;

  dobro = 2 * (*b);
  triplo = 3 * (**c);
  quadruplo = 4 * (***d);

  printf("2x: %d, 3x: %d, 4x: %d\n", dobro, triplo, quadruplo);

  return 0;
  }
