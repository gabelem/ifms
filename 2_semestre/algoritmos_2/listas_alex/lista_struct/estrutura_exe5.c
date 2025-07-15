#include <stdio.h>

struct Ponto {
    float x, y;
};

struct Retangulo {
    struct Ponto sup_esq;
    struct Ponto inf_dir;
};

int main() {
    struct Retangulo r;
    struct Ponto p;

    printf("Digite o ponto superior esquerdo do retangulo (x y): ");
    scanf("%f %f", &r.sup_esq.x, &r.sup_esq.y);

    printf("Digite o ponto inferior direito do retangulo (x y): ");
    scanf("%f %f", &r.inf_dir.x, &r.inf_dir.y);

    printf("Digite o ponto a ser testado (x y): ");
    scanf("%f %f", &p.x, &p.y);

    if (p.x >= r.sup_esq.x && p.x <= r.inf_dir.x &&
        p.y <= r.sup_esq.y && p.y >= r.inf_dir.y) {
        printf("O ponto esta dentro do retangulo.\n");
    } else {
        printf("O ponto esta fora do retangulo.\n");
    }

    return 0;
}

