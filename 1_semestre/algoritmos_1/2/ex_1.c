#include <stdio.h>


int main()
{
	float f;
	char c;
	int i;

	printf("Float: ");
	scanf(" %f", &f);

	printf("Char: ");
	scanf(" %c", &c);

	printf("Inteiro: ");
	scanf(" %i", &i);

	printf("Float: %f \tCaractere: %c \tInteiro: %d\n", f, c, i);
}
