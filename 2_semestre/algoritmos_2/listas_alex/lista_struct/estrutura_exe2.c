#include <stdio.h>
#include <math.h>

struct Ponto {
    float x, y;
};

int main() {
    struct Ponto p;

    printf("Digite as coordenadas X e Y do ponto: ");
    scanf("%f %f", &p.x, &p.y);

    float distancia = sqrt(p.x * p.x + p.y * p.y);
    printf("Distancia ate a origem: %.2f\n", distancia);
    return 0;
}

