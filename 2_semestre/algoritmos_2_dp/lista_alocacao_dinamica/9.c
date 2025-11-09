#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recebe_string(char *string)
{
  char *ptr;
  ptr = (char *) malloc(sizeof(*string));

  strcpy(ptr, string);
  printf("normal: %s\n", ptr);

  char *inicio = ptr;
  char *final = ptr + strlen(ptr) -1;
  char temporaria;

  while(inicio < final)
  {
    temporaria = *inicio;
    *inicio = *final;
    *final = temporaria;

    inicio++;
    final--;
  }
  printf("invertida: %s\n", ptr);
}

int main()
{
  recebe_string("belem");

  return 0;
}

