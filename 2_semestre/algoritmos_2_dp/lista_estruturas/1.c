#include <stdio.h>
#include <string.h>

struct Dados 
  {
  char nome[100];
  int idade;
  char endereco[100];
  };

int main() 
  {
  struct Dados aluno;

  strcpy(aluno.nome, "Gabriel Belem");
  aluno.idade = 19;
  strcpy(aluno.endereco, "Rua da minha casa 123");

  printf("Nome: %s\n", aluno.nome);
  printf("Idade: %d\n", aluno.idade);
  printf("Endereco: %s\n", aluno.endereco);

  return 0;
  }
