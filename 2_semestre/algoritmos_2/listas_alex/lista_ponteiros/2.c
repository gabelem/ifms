#include <stdio.h>

int main() 
  {
  int a,b;

  int *ponteiro1 = &a;
  int *ponteiro2 = &b;

  printf("Insira valores para a b: ");
  scanf("%d %d", &a, &b);

  if(ponteiro1 != ponteiro2) 
    {
    printf("os ponteiros nao apontam para o mesmo end.\n");
      if(ponteiro1 > ponteiro2) 
        {
        printf("%d\n", a);
	}
        else 
          {
          printf("%d\n", b);
	  }
    }
  }
