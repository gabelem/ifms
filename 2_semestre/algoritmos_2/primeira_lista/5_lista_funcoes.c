#include <stdio.h>
#include <math.h>

void segundos_para_horas(int segundos) 
  {
  printf("Insira o tempo de duracao da fabrica expressa em segundos: ");
  scanf("%d", &segundos);
  
  float horas = (float) segundos / 3600;

  printf("%d Segundos em horas= %f\n", segundos, horas);
  }

int main() 
  {
  int segundos;
  float horas;
  segundos_para_horas(segundos);
  }
