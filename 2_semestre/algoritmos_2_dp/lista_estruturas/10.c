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
  
  int k = 0;
  int j = 1;
  int guardar = 0;
  for(int i = 0; i < 5; i++)
    {
    if(quantidade[k].idade > quantidade[j].idade)
      {
      j++;
      }
      else
        {
        guardar = quantidade[k].idade;
        quantidade[k].idade = quantidade[j].idade;
        quantidade[j].idade = guardar;
        k++;
        }
    }
  
  printf("%d %d %d %d %d", quantidade[0].idade, quantidade[1].idade, quantidade[2].idade, quantidade[3].idade, quantidade[4].idade);
  return 0;
  }
