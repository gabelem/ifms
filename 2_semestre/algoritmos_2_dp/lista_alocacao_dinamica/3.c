#include <stdio.h>
#include <stdlib.h>

struct Cadastro
{
  char nome[100], endereco[255];
  int idade;
};

struct Cadastro* recebe(int N)
{
  struct Cadastro *ptr;
  ptr = (struct Cadastro *) malloc(N * sizeof(struct Cadastro));

  if(ptr == NULL)
  {
    printf("alocacao falhou\n");
  }

  return ptr;
};

int main()
{
  int N;
  printf("Determine o valor de N: ");
  scanf("%d", &N);

  struct Cadastro *pessoas = recebe(N);

  if(pessoas == NULL)
  {
    printf("alocacao falhou.");
    
    return 1;
  }

  for(int i = 0; i < N; i++)
  {
    printf("\nCadastro %d\n", i + 1);
    printf("Nome: ");
    scanf(" %[^\n]", pessoas[i].nome);
    printf("Endereco: ");
    scanf(" %[^\n]", pessoas[i].endereco);
    printf("Idade: ");
    scanf("%d", &pessoas[i].idade);
    getchar();
  }

  printf("\nDados:\n");
  for(int j = 0; j < N;j++)
  {
    printf("%d. %s, %d anos, endereco: %s\n", j+1, pessoas[j].nome, pessoas[j].idade, pessoas[j].endereco);
  }

  free(pessoas);

  return 0;
}
