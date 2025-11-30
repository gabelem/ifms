#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Forma

{
public:

  virtual void desenhar() = 0;

  virtual void mover(float dx, float dy) = 0;

  virtual float area() = 0;

  virtual float perimetro() = 0;

  virtual unique_ptr<Forma> clonar() = 0;
};

class Circulo : public Forma

{
public:
  float cx;
  float cy;
  float raio;

public:

  void desenhar() override
  {
    cout << "Desenhando círculo no centro (" << cx << ", " << cy << ") com raio " << raio << endl;
  }

  void mover(float dx, float dy) override
  {
    cx += dx;
    cy += dy;
  }

  float area() override
  {
    return 3.14f * raio * raio;
  }

  float perimetro() override
  {
    return 2 * 3.14f * raio;
  }

  unique_ptr<Forma> clonar() override
  {
    return make_unique<Circulo>(*this);
  }
};

class Retangulo : public Forma

{
public:
  float x;
  float y;
  float largura;
  float altura;

public:

  void desenhar() override
  {
    cout << "Desenhando retângulo em (" << x << ", " << y << ") "
         << "largura=" << largura << " altura=" << altura << endl;
  }

  void mover(float dx, float dy) override
  {
    x += dx;
    y += dy;
  }

  float area() override
  {
    return largura * altura;
  }

  float perimetro() override
  {
    return 2 * (largura + altura);
  }

  unique_ptr<Forma> clonar() override
  {
    return make_unique<Retangulo>(*this);
  }
};

class Poligono : public Forma

{
public:
  vector<pair<float, float>> vertices;

public:

  void desenhar() override
  {
    cout << "Desenhando polígono com " << vertices.size() << " vértices" << endl;
  }

  void mover(float dx, float dy) override
  {
    for (auto& v : vertices)
    {
      v.first += dx;
      v.second += dy;
    }
  }

  float area() override
  {
    float soma = 0;

    for (size_t i = 0; i < vertices.size(); i++)
    {
      auto& a = vertices[i];
      auto& b = vertices[(i + 1) % vertices.size()];
      soma += a.first * b.second - b.first * a.second;
    }

    return 0.5f * abs(soma);
  }

  float perimetro() override
  {
    float p = 0;

    for (size_t i = 0; i < vertices.size(); i++)
    {
      auto& a = vertices[i];
      auto& b = vertices[(i + 1) % vertices.size()];

      float dx = b.first - a.first;
      float dy = b.second - a.second;

      p += sqrt(dx*dx + dy*dy);
    }

    return p;
  }

  unique_ptr<Forma> clonar() override
  {
    return make_unique<Poligono>(*this);
  }
};

class Ferramenta

{
public:

  virtual void aplicar(Forma& f) = 0;
};

class FerramentaRedimensionar : public Ferramenta

{
public:
  float fator;

public:

  void aplicar(Forma& f) override
  {
    auto copia = f.clonar();

    if (auto c = dynamic_cast<Circulo*>(copia.get()))
    {
      c->raio *= fator;
      cout << "Redimensionando círculo com fator " << fator << endl;
    }

    if (auto r = dynamic_cast<Retangulo*>(copia.get()))
    {
      r->largura *= fator;
      r->altura *= fator;
      cout << "Redimensionando retângulo com fator " << fator << endl;
    }

    if (auto p = dynamic_cast<Poligono*>(copia.get()))
    {
      for (auto& v : p->vertices)
      {
        v.first *= fator;
        v.second *= fator;
      }

      cout << "Redimensionando polígono com fator " << fator << endl;
    }
  }
};

class FerramentaRotacionar : public Ferramenta

{
public:
  float angulo;

public:

  void aplicar(Forma& f) override
  {
    cout << "Rotacionando forma em " << angulo << " graus" << endl;
  }
};

class Renderer

{
public:
  vector<unique_ptr<Forma>> formas;

public:

  void adicionar(unique_ptr<Forma> f)
  {
    formas.push_back(move(f));
  }

  void renderizar()
  {
    for (auto& f : formas)
    {
      f->desenhar();
    }
  }
};

int main()
{
  Renderer r;

  auto c = make_unique<Circulo>();
  c->cx = 0;
  c->cy = 0;
  c->raio = 5;

  auto rect = make_unique<Retangulo>();
  rect->x = 10;
  rect->y = 10;
  rect->largura = 4;
  rect->altura = 8;

  auto poly = make_unique<Poligono>();
  poly->vertices = { {0,0}, {4,0}, {4,3} };

  r.adicionar(move(c));
  r.adicionar(move(rect));
  r.adicionar(move(poly));

  cout << "\n== Renderizando Formas ==\n";
  r.renderizar();

  cout << "\n== Aplicando Ferramentas ==\n";

  FerramentaRedimensionar fr;
  fr.fator = 2;
  fr.aplicar(*r.formas[0]);

  FerramentaRotacionar rot;
  rot.angulo = 45;
  rot.aplicar(*r.formas[1]);

  return 0;
}

