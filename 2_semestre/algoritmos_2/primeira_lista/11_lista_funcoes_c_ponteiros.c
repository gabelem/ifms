#include <stdio.h>

void media(float *nota) 
  {
  printf("Determine a nota: ");
  scanf("%f", nota);

    if(*nota >= 0.0 && *nota <= 4.9) 
      {
      printf("D");
      }

    if(*nota >= 5.0 && *nota <= 6.9) 
      {
      printf("C");
      }

    if(*nota >= 7.0 && *nota <= 8.9) 
      {
      printf("B");
      }

    if(*nota >= 9.0 && *nota <= 10.0) 
      {
      printf("A");
      }
  }

int main() 
  {
  float nota;
  media(&nota);
  }
