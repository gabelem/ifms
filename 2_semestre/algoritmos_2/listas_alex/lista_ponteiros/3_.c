#include <stdio.h>

int main() 
  {
  int i;
  float array[10] = {100.1, 200.2, 300.3, 400.4, 500.5, 600.6, 700.7, 800.8, 900.9, 1000.0};

  for(i=0; i < 10;i++)
    {
    printf("%p %f\n", array[i],array[i]);
    }
  }
