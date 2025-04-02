#include <stdio.h>
int main()

{
	int one, two, three, four;
	printf("Valor 1: ");
	scanf("%d", &one);

	printf("Valor 2: ");
	scanf("%d", &two);

	printf("Valor 3: ");
	scanf("%d", &three);

	printf("Valor 4: ");
	scanf("%d", &four);

	printf("Resultado: %d", ((one+two+three+four)/4));

	return 0;
}
