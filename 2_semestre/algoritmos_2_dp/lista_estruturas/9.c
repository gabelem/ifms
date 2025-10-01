#include <stdio.h>
#include <string.h>

struct Atleta 
  { 
  char nome[100];
  char esporte[100];
  int idade;
  float altura;
  };

int main()
  {
  struct Atleta quantidade[5];

  float mais_alto = 0;
  char nome_mais_alto[100];

  int mais_velho = 0;
  char nome_mais_velho[100];

  strcpy(quantidade[0].nome, "Cristiano Ronaldo");
  strcpy(quantidade[0].esporte, "Futebol");
  quantidade[0].idade = 40;
  quantidade[0].altura = 1.87;
  
  strcpy(quantidade[1].nome, "Gabriel Medina");
  strcpy(quantidade[1].esporte, "Surf");
  quantidade[1].idade = 31;
  quantidade[1].altura = 1.8;
  
  strcpy(quantidade[2].nome, "Rayssa Leal");
  strcpy(quantidade[2].esporte, "Skate");
  quantidade[2].idade = 17;
  quantidade[2].altura = 1.6;
  
  strcpy(quantidade[3].nome, "Ronaldo Nazario");
  strcpy(quantidade[3].esporte, "Futebol");
  quantidade[3].idade = 49;
  quantidade[3].altura = 1.83;
  
  strcpy(quantidade[4].nome, "IshowSpeed");
  strcpy(quantidade[4].esporte, "Futebol");
  quantidade[4].idade = 20;
  quantidade[4].altura = 1.78;

  
  for(int i = 0; i < 5; i++)
    {
    for(int j = 1; j < 5; j++)
      {
      while(quantidade[i].altura > quantidade[j].altura && quantidade[i].altura > mais_alto)
        {
        mais_alto = quantidade[i].altura;
	strcpy(nome_mais_alto, quantidade[i].nome);
	}
      }
    }


    for(int k = 0; k < 5; k++) 
      {
      for(int l = 1; l < 5; l++)
        {
        while(quantidade[k].idade > quantidade[l].idade && quantidade[k].idade > mais_velho)
	  {
	  mais_velho = quantidade[k].idade;
	  strcpy(nome_mais_velho, quantidade[k].nome);
	  }
	}
      }
      printf("Maior altura: %s %f\n", nome_mais_alto, mais_alto);
      printf("Mais velho: %s %d\n", nome_mais_velho, mais_velho);
    return 0;
    }
