#include <iostream>
#include <string>
using namespace std;

class Comercio_Online
  {
  string produto, pedido, forma_de_pagamento, nome_cliente, status_da_compra;
  public:
  Comercio_Online(string p, string ped, string fdp, string nc, string sdc) : produto(p), pedido(ped), forma_de_pagamento(fdp), nome_cliente(nc), status_da_compra(sdc)
    {
    cout << "[Construtor] " << "Produto: " << produto << ", Codigo do pedido: " << pedido << ", Forma de pagamento: " << forma_de_pagamento << ", Nome do cliente: " << nome_cliente << ", Status da compra: " << status_da_compra << "\n";
    }

  ~Comercio_Online()
    {
    cout << "[Destrutor] " << "Produto: " << produto << ", Codigo do pedido: " << pedido << ", Forma de pagamento: " << forma_de_pagamento << ", Nome do cliente: " << nome_cliente << ", Status da compra: " << status_da_compra << "\n";
    }
  };

int main()
  {
  Comercio_Online Venda("Monitor", "GK5IG9", "PIX", "Douglas", "Pendente");

  return 0;
  }
