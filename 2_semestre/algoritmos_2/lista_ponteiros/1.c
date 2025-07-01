#include <stdio.h>

int main() 
  {
  int a = 0;
  int b = 1;

  int *ponteiro1 = &a;
  int *ponteiro2 = &b;

  if(ponteiro1 == ponteiro2) 
    {
    printf("ponteiro1 e o ponteiro2 apontam para o mesmo endereco de memoria.\n");
    }
  else 
    {
    printf("os ponteiros nao apontam para o mesmo endereco de memoria.\n");
    }

  if(ponteiro1 > ponteiro2)
    {
    printf("[ponteiro1] %p > [ponteiro2] %p\n", ponteiro1,ponteiro2);
    }
  else 
    {
    printf("[ponteiro2] %p > [ponteiro1] %p\n", ponteiro2,ponteiro1);
    }
  }
