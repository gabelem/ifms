#include <iostream>
#include <vector>
#include <string>
using namespace std;

class EstrategiaRecarga
{

public:
  virtual void recarregar() = 0;
  virtual ~EstrategiaRecarga() {}
};

class RecargaRapida
: public EstrategiaRecarga
{

public:
  void recarregar() override {
    cout << "Recarga rapida.\n";
  }
};

class RecargaLenta
: public EstrategiaRecarga
{

public:
  void recarregar() override {
    cout << "Recarga lenta.\n";
  }
};

class Sensor
{

public:
  virtual bool detectarObstaculos() = 0;
  virtual ~Sensor() {}
};

class SensorBasico
: public Sensor
{

public:
  bool detectarObstaculos() override {
    return false;
  }
};

class SensorAvancado
: public Sensor
{

public:
  bool detectarObstaculos() override {
    return true;
  }
};

class VeiculoAutonomo
{

protected:
  string id;
  int posicao = 0;
  int bateria = 100;
  EstrategiaRecarga* recarga = nullptr;
  Sensor* sensor = nullptr;

public:
  virtual ~VeiculoAutonomo() {}

  void setRecarga(EstrategiaRecarga* r) { recarga = r; }
  void setSensor(Sensor* s) { sensor = s; }

  virtual float consumoPorKm() = 0;

  virtual void planejarRota(string destino) {
    cout << id << " planejando rota para " << destino << endl;
  }

  virtual void mover() {
    if (sensor && sensor->detectarObstaculos()) {
      cout << id << " encontrou obstaculo, parando." << endl;
      return;
    }
    bateria -= static_cast<int>(consumoPorKm());
    posicao++;
    cout << id << " moveu para posicao " << posicao << endl;
  }

  virtual void relatorioStatus() {
    cout << "[" << id << "] pos: " << posicao
         << " bateria: " << bateria << "%" << endl;
  }
};

class CarroAutonomo
: public VeiculoAutonomo
{

public:
  CarroAutonomo(string nome) { id = nome; }
  float consumoPorKm() override { return 2.0f; }
};

class CaminhaoAutonomo
: public VeiculoAutonomo
{

public:
  CaminhaoAutonomo(string nome) { id = nome; }
  float consumoPorKm() override { return 5.0f; }

  void planejarRota(string destino) override {
    cout << id << " usando rota sem restricoes de peso." << endl;
  }
};

class OnibusAutonomo
: public VeiculoAutonomo
{

public:
  OnibusAutonomo(string nome) { id = nome; }
  float consumoPorKm() override { return 3.0f; }

  void planejarRota(string destino) override {
    cout << id << " escolhendo vias com pontos de parada." << endl;
  }
};

class Despachante
{

public:
  void despachar(vector<VeiculoAutonomo*>& frota) {
    for (auto v : frota) {
      v->planejarRota("Centro");
      v->mover();
      v->relatorioStatus();
    }
  }
};

int main()
{
  CarroAutonomo c1("Carro-1");
  CaminhaoAutonomo k1("Caminhao-1");
  OnibusAutonomo o1("Onibus-1");

  vector<VeiculoAutonomo*> frota = { &c1, &k1, &o1 };

  Despachante d;
  d.despachar(frota);

  return 0;
}

