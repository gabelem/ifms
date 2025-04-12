#include <stdio.h>
#include <math.h>

void n_perfeito() 
  {
  int n=0; 

  printf("Defina o valor de n: ");
  scanf("%d", &n);

  int n_menos_um = n-1;

  int i=1, j=1;

  int lado_e=2, lado_d=2;

    for(i=1; i < n_menos_um;i++) 
    {
    lado_e = lado_e * 2;
    }

    for(j=1; j < n;j++) 
    {
    lado_d = lado_d * 2; 
    }
    lado_d = lado_d -1;

    printf("Resultado= %d*%d=%d\n", (lado_e),(lado_d),((lado_e)*(lado_d)));
  }

int main() 
  {
  n_perfeito();
  }
