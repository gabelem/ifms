#include <stdio.h>
#include <math.h>

struct Retangulo
  {
  char superior_esquerdo;
  char inferior_direito;
  };

struct Ponto
  {
  int X,Y;
  };

int main()
  {
  struct Retangulo ponto1;

  ponto1.superior_esquerdo = 'A';
  ponto1.inferior_direito = 'B';

  struct Ponto primeiro;

  primeiro.X = 2;
  primeiro.Y = 2;

  int comprimento;

  comprimento = (primeiro.X*primeiro.X)+(primeiro.Y*primeiro.Y);

  printf("Area do retangulo = %d\n", (primeiro.X*primeiro.Y));
  printf("Comprimento da diagonal = %f\n", sqrt(comprimento));
  printf("Perimetro do retangulo = %d\n", 2*(primeiro.X+primeiro.Y));

  return 0;
  }
