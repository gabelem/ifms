#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *clientes = fopen("clientes.dat", "wb");
    FILE *recebimentos = fopen("recebimentos.dat", "wb");

    if (!clientes || !recebimentos) {
        printf("Erro ao criar arquivos.\n");
        return 1;
    }

    printf("Arquivos criados com sucesso.\n");
    fclose(clientes);
    fclose(recebimentos);
    return 0;
}

