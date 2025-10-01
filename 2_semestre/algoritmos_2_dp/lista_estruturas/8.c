#include <stdio.h>
#include <string.h>

struct Pessoas 
  {
  char nome[100];
  int idade;
  };
  
int main() 
  {
  struct Pessoas dados[6];
  struct Pessoas maior, menor;

  strcpy(dados[0].nome, "Cristiano");
  dados[0].idade = 30;
  
  strcpy(dados[1].nome, "Valdemir");
  dados[1].idade = 24;
  
  strcpy(dados[2].nome, "Bernardo");
  dados[2].idade = 22;
  
  strcpy(dados[3].nome, "Cleriton");
  dados[3].idade = 20;
  
  strcpy(dados[4].nome, "Oswaldo");
  dados[4].idade = 18;
  
  strcpy(dados[5].nome, "Bitelo");
  dados[5].idade = 16;

  maior.idade = 0;
  menor.idade = 100;

  char nome_maior[100];
  char nome_menor[100];

  for(int i = 0 ; i < 6; i++)
    {
    for(int j = 1; j < 6; j++)
      {
      if(dados[i].idade > dados[j].idade && dados[i].idade > maior.idade)
        {
        maior.idade = dados[i].idade;
	strcpy(maior.nome, dados[i].nome);
	}
      }
    }

  for(int k = 0; k < 6; k++)
    {
    for(int l = 1; l < 6; l++)
      {
      while(dados[k].idade > dados[l].idade && dados[l].idade < menor.idade)
        {
        menor.idade = dados[l].idade;
	strcpy(menor.nome, dados[l].nome);
	}
      }
    }

  printf("Maior idade: %s %d\nMenor idade: %s %d\n", maior.nome, maior.idade, menor.nome, menor.idade);

  return 0;
  }
