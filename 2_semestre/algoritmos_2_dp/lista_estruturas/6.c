#include <stdio.h>
#include <string.h>

struct Aluno 
  {
  int matricula;
  char nome[100];
  float materia_circuitos, materia_algoritmos, materia_poo;
  int media;
  };

int main() 
  {
  struct Aluno A;
  A.matricula = 001;
  strcpy(A.nome, "Gabriel Belem de Moraes");

  A.materia_circuitos = 10;
  A.materia_algoritmos = 10;
  A.materia_poo = 10;
  A.media = (float)(A.materia_circuitos + A.materia_algoritmos + A.materia_poo)/3;

  struct Aluno B;
  B.matricula = 002;
  strcpy(B.nome, "Jubiscleuson Theonorio Terceiro da Silva");

  B.materia_circuitos = 1;
  B.materia_algoritmos = 1;
  B.materia_poo = 1;
  B.media = (float)(B.materia_circuitos + B.materia_algoritmos + B.materia_poo)/3;

  struct Aluno C;
  C.matricula = 003;
 strcpy(C.nome, "Oswaldo Peixeiro Segundo Lima Limao");

  C.materia_circuitos = 2;
  C.materia_algoritmos = 2;
  C.materia_poo = 2;
  C.media = (float)(C.materia_circuitos + C.materia_algoritmos + C.materia_poo)/3;
  
  struct Aluno D;
  D.matricula = 004;
  strcpy(D.nome, "Peixonauta Bate Palmas com os amigos a brincar");

  D.materia_circuitos = 3;
  D.materia_algoritmos = 3;
  D.materia_poo = 3;
  D.media = (float)(D.materia_circuitos + D.materia_algoritmos + D.materia_poo)/3;
  
  struct Aluno E;
  E.matricula = 005;
  strcpy(E.nome, "Takamassa no-muro-chan");

  E.materia_circuitos = 8;
  E.materia_algoritmos = 8;
  E.materia_poo = 8;
  E.media = (float)(E.materia_circuitos + E.materia_algoritmos + E.materia_poo)/3;

  printf("Aluno com a maior media:\n");
  printf("Nome:%s Notas: %f, %f, %f\n",A.nome, A.materia_circuitos, A.materia_algoritmos, A.materia_poo);

  return 0;
  }
