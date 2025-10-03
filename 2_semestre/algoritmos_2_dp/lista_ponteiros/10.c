#include <stdio.h>

int main()
  {
  int a;
  int *b;
  int **c;
  int ***d;

  a = 2;

  b = &a;
  *b = *b;

  c = &b;

  d = &c;

  printf("%d %d %d %d", a, (*b*2), (**c*3), (***d*4));

  return 0;
  }
