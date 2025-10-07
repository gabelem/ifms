#include <iostream>
#include <array>
#include <cstring>

using namespace std;

class Biblioteca
  {
  public:
  char titulo[100];
  char autor[100];
  int ano_de_publicacao;
  };

int main()
  {
  int quantidade = 1;
  Biblioteca Livro[quantidade];

  strcpy(Livro[0].titulo,"Titulo");
  strcpy(Livro[0].autor,"Autor");
  Livro[0].ano_de_publicacao = 0000;

  int escolha = 0;

    do
    {
    cout << "\n1. Adicionar Livro\n2. Listar\n3. Fechar\n: ";
    cin >> escolha;
    cout << "\n";

    if(escolha == 1)
      {
      cout << "Utilize a seguinte sequencia para adicionar teu livro (Titulo) (Autor) (Ano de publicacao)\n: ";
      cin >> Livro[quantidade].titulo >> Livro[quantidade].autor >> Livro[quantidade].ano_de_publicacao;
      quantidade++;
      }


    if(escolha == 2)
      {
      for(int i = 0; i < quantidade; i++)
        {
        cout << Livro[i].titulo << " " << Livro[i].autor << " " << Livro[i].ano_de_publicacao << "\n";
	}
      }
    }while(escolha != 3);

  return 0;
  }
