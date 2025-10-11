#include <iostream>
#include <string>
using namespace std;

class Clinica
  {
  string nome_paciente;
  string sintomas;
  string medicacao;
  string medico_responsavel;

  public:
  Clinica(string nome_p, string sintom, string medicame, string med_resp) : nome_paciente(nome_p), sintomas(sintom), medicacao(medicame), medico_responsavel(med_resp)
    {
    cout << "[Construtor] " << "Paciente: " << nome_paciente << ", Sintomas: " << sintomas << ", Medicamentos necessarios: " << medicacao << ", Medico responsavel: " << medico_responsavel << "\n";
    }

  ~Clinica()
  {
  cout << "[Destrutor] " << "Paciente: " << nome_paciente << ", Sintomas: " << sintomas << ", Medicamentos necessarios: " << medicacao << ", Medico responsavel: " << medico_responsavel << "\n";
  }
  };

int main()
  {
  Clinica paciente1("Cleitin", "Dengoso", "Mt saude", "Flavio do pneu");

  return 0;
  }
