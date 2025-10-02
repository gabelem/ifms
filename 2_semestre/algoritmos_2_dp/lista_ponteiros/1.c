#include <stdio.h>

int main()
  {
  int a,b;

  printf("Endereco de 'a': %p\n",&a);
  printf("Endereco de 'b': %p\n", &b);

  if(&a > &b)
    {
    printf("(a): %p > (b): %p\n", &a, &b);
    }
    else
      {
      printf("(a): %p < (b): %p\n", &a, &b);
      }
  return 0;
  }
