#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod_cli;
    char nome[50];
    char endereco[100];
    char fone[20];
} Cliente;

typedef struct {
    int num_doc;
    float valor_doc;
    char data_emissao[11];
    char data_vencimento[11];
    int cod_cli;
} Recebimento;

void excluir_cliente(int codigo) {
    FILE *orig_cli = fopen("clientes.dat", "rb");
    FILE *tmp_cli = fopen("temp_cli.dat", "wb");

    Cliente c;

    while (fread(&c, sizeof(Cliente), 1, orig_cli)) {
        if (c.cod_cli != codigo)
            fwrite(&c, sizeof(Cliente), 1, tmp_cli);
    }

    fclose(orig_cli);
    fclose(tmp_cli);
    remove("clientes.dat");
    rename("temp_cli.dat", "clientes.dat");

    // Agora remover os recebimentos do cliente
    FILE *orig_rec = fopen("recebimentos.dat", "rb");
    FILE *tmp_rec = fopen("temp_rec.dat", "wb");
    Recebimento r;

    while (fread(&r, sizeof(Recebimento), 1, orig_rec)) {
        if (r.cod_cli != codigo)
            fwrite(&r, sizeof(Recebimento), 1, tmp_rec);
    }

    fclose(orig_rec);
    fclose(tmp_rec);
    remove("recebimentos.dat");
    rename("temp_rec.dat", "recebimentos.dat");

    printf("Cliente e seus recebimentos excluídos.\n");
}

int main() {
    int cod;
    printf("Digite o código do cliente a excluir: ");
    scanf("%d", &cod);
    excluir_cliente(cod);
    return 0;
}

