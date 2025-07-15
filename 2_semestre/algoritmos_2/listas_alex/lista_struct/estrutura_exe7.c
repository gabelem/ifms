#include <stdio.h>

struct Hora {
    int h, m, s;
};

int main() {
    struct Hora horas[5];
    int i, maior = 0;

    for (i = 0; i < 5; i++) {
        printf("Hora %d (hh mm ss): ", i + 1);
        scanf("%d %d %d", &horas[i].h, &horas[i].m, &horas[i].s);
    }

    for (i = 1; i < 5; i++) {
        if (horas[i].h > horas[maior].h ||
            (horas[i].h == horas[maior].h && horas[i].m > horas[maior].m) ||
            (horas[i].h == horas[maior].h && horas[i].m == horas[maior].m && horas[i].s > horas[maior].s)) {
            maior = i;
        }
    }

    printf("Maior hora: %02d:%02d:%02d\n", horas[maior].h, horas[maior].m, horas[maior].s);
    return 0;
}

