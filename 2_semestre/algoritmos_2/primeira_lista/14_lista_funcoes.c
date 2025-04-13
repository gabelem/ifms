#include <stdio.h>

void media_aritmetica() 
  {
  int guardar_valor=0, somar_valor=1, contador_de_valores=0;
  float media=0;

  while(somar_valor != 0)
    {
    printf("Determine os valores [DIGITE 0 PARA FINALIZAR]: ");
    scanf("%d", &somar_valor);

    guardar_valor = guardar_valor + somar_valor;
    contador_de_valores = contador_de_valores + 1;
    }
    contador_de_valores = contador_de_valores - 1;
    media = (float)guardar_valor/contador_de_valores;
    
    
 
    printf("%d/%d=%f\n",guardar_valor,contador_de_valores,media);
  }

int main() 
  {
  media_aritmetica();
  }
