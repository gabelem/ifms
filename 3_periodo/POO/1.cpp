#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Biblioteca
  {
  public:
  string titulo;
  string autor;
  int ano_de_publicacao; 
  };

int main()
  {
  int quantidade = 0;
  struct Biblioteca Livro;

  cout << "Digite a quantidade de livros para registrar: ";
  cin >> quantidade;

  for(int i = 0; i < 1; i++)
    {
    cout << "Digite no seguinte formato (titulo) (autor) (ano_de_publicacao): ";
    cin >> Livro.titulo >> Livro.autor >> Livro.ano_de_publicacao;
    cout << Livro.titulo << " " << Livro.autor << " " << Livro.ano_de_publicacao << "\n";
    }

  return 0;
  }
