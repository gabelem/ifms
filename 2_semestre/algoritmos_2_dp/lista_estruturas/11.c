#include <stdio.h>

struct Data
  {
  int dia, mes, ano;
  };

int main()
  {
  struct Data data[2];
  data[0].dia = 01;
  data[0].mes = 10;
  data[0].ano = 2025;

  data[1].dia = 12;
  data[1].mes = 12;
  data[1].ano = 2026;

  if(data[1].ano > data[0].ano)
    {
    printf("Se passou %d ano(s).\n", (data[1].ano-data[0].ano));
    }
  
  if(data[1].mes > data[0].mes)
    {
    printf("Se passou %d mes(es).\n", (data[1].mes-data[0].mes));
    }
  if(data[1].dia > data[0].dia)
    {
    printf("Se passou %d dia(s).\n", (data[1].dia-data[0].dia));
    }

  return 0;
  }
