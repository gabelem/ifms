#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

class Pedido
  {
  string produto;
  int quantidade;
  int preco_unitario;
  
  public:
  Pedido(string prod, int quant, int preco) : produto(prod), quantidade(quant), preco_unitario(preco)
    {
    cout << "[Construtor da classe Pedido] " << produto << ", " << quantidade << ", " << preco_unitario << "\n";
    }

  ~Pedido()
    {
    cout << "[Destrutor da classe Pedido] " << produto << ", " << quantidade << ", " << preco_unitario << "\n";
    }
  };

int main()
  {
  Pedido Gabriel("Teclado", 1, 200);
  return 0;
  }
