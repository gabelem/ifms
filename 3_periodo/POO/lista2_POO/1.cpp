#include <iostream>
#include <string>
using namespace std;

class Funcionario
{
public:
  int id;
  string nome, documentos;

  virtual int calcularRemuneracao() = 0;
};

class Assalariado : public Funcionario
{
public:
  int salarioFixo;

  virtual int calcularRemuneracao() override
  {
    return salarioFixo;
  }
};

class Horista : public Funcionario
{
public:
  int valorHora;
  int horasTrabalhadas;

  int calcularRemuneracao() override
  {
    int normal = (horasTrabalhadas <= 44) ? horasTrabalhadas : 44;
    int extras = (horasTrabalhadas > 44) ? horasTrabalhadas - 44 : 0;

    return (normal * valorHora) + (extras * valorHora * 1.5);
  }
};

class Comissionado : public Funcionario
{
public:
  int salarioBase;
  int taxaComissao;
  int totalVendas;

  int calcularRemuneracao() override
  {
    return salarioBase + (totalVendas * taxaComissao/ 100 );
  }
};

int main()
{
  Assalariado f1;
  f1.id = 1;
  f1.nome = "Beto";
  f1.documentos = "123.456.789-00";
  f1.salarioFixo = 5000;

  Horista f2;
  f2.id = 1;
  f2.nome = "Rogerio";
  f2.documentos = "123.456.789-00";
  f2.valorHora = 50;
  f2.horasTrabalhadas = 1;

  Comissionado f3;
  f3.id = 1;
  f3.nome = "Alex";
  f3.documentos = "123.456.789-00";
  f3.salarioBase = 2000;
  f3.taxaComissao = 10;
  f3.totalVendas = 15000;

  cout << f1.nome << ": R$ " << f1.calcularRemuneracao() << endl;
  cout << f2.nome << ": R$ " << f2.calcularRemuneracao() << endl;
  cout << f3.nome << ": R$ " << f3.calcularRemuneracao() << endl;

  return 0;
}
