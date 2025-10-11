#include <iostream>
#include <string>
#include <vector>
using namespace std;

//POSSUI COMPOSICAO
class Jogador
  {
  string nome_item, nome_arma, nickname;
  int item_peso, quantidade_dano_arma;

  public: 
  Jogador(string ni, string na, string nn, int ip, int qda) : nome_item(ni), nome_arma(na), nickname(nn), item_peso(ip), quantidade_dano_arma(qda)
  {
  cout << "[Construtor] Jogador, " << "Nickname: " << nickname << ", " << "Arma: " << nome_arma << ", " << "Nome do item: " << nome_item << "\n";
  }

  ~Jogador()
    {
    cout << "[Destrutor] Jogador, " << "Nickname: " << nickname << ", " << "Arma: " << nome_arma << ", " << "Nome do item: " << nome_item << "\n";
    }
  };

// POSSUI AGREGACAO
class Inimigo
  {
  string nome_arma_inimigo;
  int hp;
	  
  public:
  Inimigo(string nai, int life) : nome_arma_inimigo(nai), hp(life)
    {
    cout << "[Construtor] Inimigo " << "Arma: " << nome_arma_inimigo << " ,HP: " << hp << "\n";
    }

    ~Inimigo()
    {
    cout << "[Destrutor] Inimigo " << "Arma: " << nome_arma_inimigo << " ,HP: " << hp << "\n";
    }
  };

int main()
  {
  Jogador("Suco de uva", "Sniper", "Cleitoon", 1, 2);
  Inimigo("Espada de ferro", 10);

  return 0;
  }
