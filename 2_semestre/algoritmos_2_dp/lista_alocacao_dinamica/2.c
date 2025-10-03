#include <stdio.h>
#include <string.h>

struct Alunos
  {
  int matricula;
  char nome[100];
  float circuitos_eletricos, algoritmos, calculo;
  };

int main()
  {
  struct Alunos aluno1;

  aluno1.matricula = 40028922;
  strcpy(aluno1.nome, "Gabriel Belem");
  aluno1.circuitos_eletricos = 10;
  aluno1.algoritmos = 10;
  aluno1.calculo = 10;

  printf("tamanho da struct: %d\n", sizeof(aluno1));
  }
