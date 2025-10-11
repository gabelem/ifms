#include <iostream>
#include <string>
using namespace std;

class Instituto
  {
  string turma, professor;
  int quantia_alunos;

  public:
  Instituto(string t, string p, int qa) : turma(t), professor(p), quantia_alunos(qa)
    {
    cout << "[Construtor] " << "Turma: " << turma << ", Professor: " << professor << ", Quantidade de alunos matriculados: " << quantia_alunos << "\n";
    }

  ~Instituto()
    {
    cout << "[Destrutor] " << "Turma: " << turma << ", Professor: " << professor << ", Quantidade de alunos matriculados: " << quantia_alunos << "\n";
    }
  };

int main()
  {
  Instituto Computacao("A", "Beto", 23);

  return 0;
  }
