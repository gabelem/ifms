#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Midia
{
public:
    string titulo;
    int ano;
    string duracao;

    virtual void abrir() = 0;
    virtual void reproduzir() = 0;
    virtual void infoDetalhada() = 0;
    
    virtual bool combina(const string& filtro) = 0;
};

class Musica : public Midia
{
public:
    string artista;

    void abrir() override
    {
        cout << "Abrindo musica: " << titulo << endl;
    }

    void reproduzir() override
    {
        cout << "Reproduzindo musica de: " << artista << endl;
    }

    void infoDetalhada() override
    {
        cout << "[MÚSICA] " << titulo << " - " << artista << endl;
    }

    bool combina(const string& filtro) override
    {
        return artista == filtro;
    }
};

class Video : public Midia
{
public:
    string resolucao;

    void abrir() override
    {
        cout << "Abrindo video: " << titulo << endl;
    }

    void reproduzir() override
    {
        // corrigido erro: 'resoslucao'
        cout << "Reproduzindo video em " << resolucao << endl;
    }

    void infoDetalhada() override
    {
        cout << "[VIDEO] " << titulo << " - " << resolucao << endl;
    }

    bool combina(const string& filtro) override
    {
        return resolucao == filtro;
    }
};

class Podcast : public Midia
{
public:
    string host;

    void abrir() override
    {
        cout << "Abrindo podcast " << titulo << endl;
    }

    void reproduzir() override
    {
        cout << "Podcast com host " << host << endl;
    }

    void infoDetalhada() override
    {
        cout << "[PODCAST] " << titulo << " - host: " << host << endl;
    }

    bool combina(const string& filtro) override
    {
        return host == filtro;
    }
};

class Gerenciador
{
public:
    vector<unique_ptr<Midia>> itens;

    void adicionar(unique_ptr<Midia> m)
    {
        itens.push_back(move(m));
    }

    void listar()
    {
        for (auto& m : itens)
        {
            cout << "- " << m->titulo << endl;
        }
    }

    void filtrar(const string& filtro)
    {
        for (auto& m : itens)
        {
            if (m->combina(filtro))
            {
                cout << "Combina: " << m->titulo << endl;
            }
        }
    }
};

int main()
{
    Gerenciador g;
    
    auto m1 = make_unique<Musica>();
    m1->titulo = "Hype";
    m1->artista = "Belem";

    auto v1 = make_unique<Video>();
    v1->titulo = "Hype (Clipe)";
    v1->resolucao = "1080p";

    auto p1 = make_unique<Podcast>();
    p1->titulo = "Behind The Scenes";
    p1->host = "30PraUm";

    g.adicionar(move(m1));
    g.adicionar(move(v1));
    g.adicionar(move(p1));

    cout << "Lista:\n";
    g.listar();

    cout << "\nFiltrar por '1080p':\n";
    g.filtrar("1080p");

    cout << "\nAbrindo e reproduzindo tudo:\n";
    for (auto& item : g.itens)
    {
        item->abrir();
        item->reproduzir();
    }

    return 0;
}

