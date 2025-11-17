#include <stdio.h>

int main()

{
    int a, b, c, d, e;
    int v[5];

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    v[4] = e;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    printf("Crescente: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }

    printf("\nDecrescente: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", v[i]);
    }

    return 0;
}

