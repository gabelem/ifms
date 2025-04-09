#include <stdio.h>

void texto_por_parametro(char *texto2) 
  {
  printf(texto2);
  }

int main() 
  {
  char texto2[100] = "04.08.25\n";
  texto_por_parametro(texto2);

  return(printf("Ok\n"));
  }
