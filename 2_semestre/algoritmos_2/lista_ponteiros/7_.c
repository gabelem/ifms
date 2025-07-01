#include <stdio.h>

int funcao(const char *str1, const char *str2)
  {
  const char *p1 = str1;

  while(*p1 != '\0') 
    {
    const char *p2 = p1;
    const char *pstr2 = str2;

    while(*p2 == *pstr2 && *pstr2 != '\0') 
      {
      p2++;
      pstr2++;
      }

    if (*pstr2 == '\0') 
      {
      return 1;
      }
      p1++;
    }
    return 0;
  }

  int main() 
  {
  const char *texto = "meu prorama em C";
  const char *buscador = "meu";

  if(funcao(texto, buscador)) 
    {
    printf("ocorre!\n");
    }
  else 
    {
    printf("nao ocorre.\n");
    }
    return 0;
  }
