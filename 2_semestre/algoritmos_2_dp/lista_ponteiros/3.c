#include <stdio.h>

int main()
  {
  float teste[10];

  for(int i = 0; i < 10; i++)
    {
    printf("endereço de teste[%d] = %p\n", i, &teste[i]);
    }

  return 0;
  }
