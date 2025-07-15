#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int dia, mes, ano;
};

int main() {
    struct Pessoa pessoas[6];
    int i, mais_nova = 0, mais_velha = 0;

    for (i = 0; i < 6; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        getchar();
        fgets(pessoas[i].nome, 100, stdin);
        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
    }

    for (i = 1; i < 6; i++) {
        // Comparar ano, mês e dia
        if (pessoas[i].ano < pessoas[mais_velha].ano ||
            (pessoas[i].ano == pessoas[mais_velha].ano && pessoas[i].mes < pessoas[mais_velha].mes) ||
            (pessoas[i].ano == pessoas[mais_velha].ano && pessoas[i].mes == pessoas[mais_velha].mes && pessoas[i].dia < pessoas[mais_velha].dia)) {
            mais_velha = i;
        }

        if (pessoas[i].ano > pessoas[mais_nova].ano ||
            (pessoas[i].ano == pessoas[mais_nova].ano && pessoas[i].mes > pessoas[mais_nova].mes) ||
            (pessoas[i].ano == pessoas[mais_nova].ano && pessoas[i].mes == pessoas[mais_nova].mes && pessoas[i].dia > pessoas[mais_nova].dia)) {
            mais_nova = i;
        }
    }

    printf("\nMais velha: %s", pessoas[mais_velha].nome);
    printf("Mais nova: %s", pessoas[mais_nova].nome);
    return 0;
}

