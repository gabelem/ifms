#include <iostream>
#include <string>
using namespace std;

class Playlist
  {
  string nome_playlist, usuario;

  public:
  Playlist(string nome_play, string user) : nome_playlist(nome_play), usuario(user)
  {
  cout << "[Construtor da Classe Playlist] " << "Nome da Playlist: " << nome_playlist << ", Playlist de: " << usuario << "\n";
  }

  ~Playlist()
    {
    cout << "[Destrutor da Classe Playlist] " << "Nome da Playlist: " << nome_playlist << ", Playlist de: " << usuario << "\n";
    }
  };

class Usuario
  {
  string nome_musica, artista;
  int minutos, segundos;

  public:
  Usuario(string nome_msc, string artist, int min, int seg) : nome_musica(nome_msc), artista(artist), minutos(min), segundos(seg)
  {
  cout << "[Construtor da Classe Usuario]" << " Nome da musica: " << nome_musica << ", Artista: " << artista << ", Duracao: " << minutos << ":" << segundos << "\n";
  }

  ~Usuario()
  {
  cout << "[Destrutor da Classe Usuario]" << " Nome da musica: " << nome_musica << ", Artista: " << artista << ", Duracao: " << minutos << ":" << segundos << "\n";
  }


  };

int main()
  {
  Playlist("Trap", "Gabriel");
  Usuario("L.A", "Belem", 2, 40);

  return 0;
  }
