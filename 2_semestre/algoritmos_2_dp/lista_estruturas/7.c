#include <stdio.h>

struct hora
  {
  int hora, minuto, segundo;
  };

int main()
  {
  struct hora relogio[5];

  relogio[0].hora = 20;
  relogio[0].minuto = 00;
  relogio[0].segundo = 00;
  
  relogio[1].hora = 21;
  relogio[1].minuto = 00;
  relogio[1].segundo = 00;
  
  relogio[2].hora = 22;
  relogio[2].minuto = 00;
  relogio[2].segundo = 00;
  
  relogio[3].hora = 23;
  relogio[3].minuto = 00;
  relogio[3].segundo = 00;
  
  relogio[4].hora = 19;
  relogio[4].minuto = 00;
  relogio[4].segundo = 00;
  
  struct hora maior_horario[1];
  
  int j = 1;
  for(int i=0; i < 5;i++) 
    {
    if(relogio[i].hora > relogio[j].hora) 
      {
      maior_horario[0].hora = relogio[i].hora;
      maior_horario[0].minuto = relogio[i].minuto;
      maior_horario[0].segundo = relogio[i].segundo;
      } else 
        {
        j++;
        }
    }
    
    printf("Maior horario:  %d:%d:%d\n", maior_horario[0].hora, maior_horario[0].minuto, maior_horario[0].segundo);

  return 0;
  }
