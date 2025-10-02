#include <stdio.h>
#include <string.h>

int recebe_string(char string1[100], char string2[100])
  {
  printf("String 1: %s, String 2: %s\n\n",string1, string2);

  char *ocorre = strstr(string1, string2);

  if(ocorre != NULL)
    {
    printf("%s ocorre em %s no indice %ld\n", string1, string2, ocorre - string1);
    } 
    else
      {
      printf("Nao ocorre\n");
      }

  return 0;
  };

int main()
  {
  char x[100];
  char y[100];

  recebe_string(strcpy(x, "Gabriel Belem"), strcpy(y, "Gabriel"));
  }
