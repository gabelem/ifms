#include <iostream>
#include <string>
using namespace std;

class Empresa
  {
  string rota, parada, motorista;

  public:
  Empresa(string r, string p, string m) : rota(r), parada(p), motorista(m)
  {
  cout << "[Construtor] " << "Rota: " << rota << " ;Parada: " << parada << " ;Motorista: " << motorista << "\n";
  }

  ~Empresa()
  {
  cout << "[Desstrutor] " << "Rota: " << rota << " ;Parada: " << parada << " ;Motorista: " << motorista << "\n";
  }
  };

int main()
  {
  Empresa onibus1("Curitiba", "SP, Campinas, TL", "Danilo");

  return 0;
  }
