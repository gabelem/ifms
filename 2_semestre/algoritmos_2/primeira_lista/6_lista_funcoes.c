#include <stdio.h>
#include <math.h>

void receba(int idade) 
  {
  printf("Insira sua idade: ");
  scanf("%d", &idade);

  printf("Anos = %d, Meses= %d, Dias= %d", idade, (idade*12), (idade*365));
  }

int main() 
  {
  int idade;
  receba(idade);
  }
