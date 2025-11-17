#include <stdio.h>

int main()

{
    int n;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        if (n > 25 && n < 85) {
            printf("%d ", n);
        }
    }

    return 0;
}

