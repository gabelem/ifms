#include <stdio.h>
#include <math.h>

struct Retangulo
  {
  int superior_esquerdo;
  int inferior_direito;
  };

struct Ponto
  {
  int X,Y;
  };

int main()
  {
  struct Retangulo ponto1;

  ponto1.superior_esquerdo = 10;
  ponto1.inferior_direito = 10;

  struct Ponto primeiro;

  primeiro.X = 5;
  primeiro.Y = 5;

  if(primeiro.X && primeiro.Y < ponto1.superior_esquerdo && ponto1.inferior_direito)
    {
    printf("Esta dentro do retangulo\n");
    }
    else
      {
      printf("Esta Fora do retangulo\n");
      }

  return 0;
  }
