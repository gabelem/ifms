#include <stdio.h>
#include <math.h>

struct Ponto {
    float x, y;
};

struct Retangulo {
    struct Ponto sup_esq;
    struct Ponto inf_dir;
};

int main() {
    struct Retangulo r;
    float largura, altura, area, perimetro, diagonal;

    printf("Digite as coordenadas do ponto superior esquerdo (x y): ");
    scanf("%f %f", &r.sup_esq.x, &r.sup_esq.y);

    printf("Digite as coordenadas do ponto inferior direito (x y): ");
    scanf("%f %f", &r.inf_dir.x, &r.inf_dir.y);

    largura = fabs(r.inf_dir.x - r.sup_esq.x);
    altura = fabs(r.sup_esq.y - r.inf_dir.y);
    area = largura * altura;
    perimetro = 2 * (largura + altura);
    diagonal = sqrt(largura * largura + altura * altura);

    printf("Area: %.2f\nPerimetro: %.2f\nDiagonal: %.2f\n", area, perimetro, diagonal);
    return 0;
}

