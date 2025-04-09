#include <stdio.h>

void texto_por_parametro(char *textinho)
  {
  printf(textinho);
  }

int main()
  {
  char texto[100] = "Hello world.\n";
  
  texto_por_parametro(texto);

  return(0);
  }
