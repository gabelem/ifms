#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	int n1,n2;

	printf("Insira o primeiro número: ");
	scanf("%d", &n1);

	printf("Insira o segundo número: ");
	scanf("%d", &n2);

	if(n1 > n2) 
	{
		printf("O NÚMERO %d é MAIOR que %d ", n1, n2);
	}	
	
	if(n2 > n1)
	{
		printf("O NÚMERO %d é MAIOR que %d ", n2, n1);
	}

	if (n1 == n2) 
	{
		printf("AMBOS SÃO IGUAIS");
	}

	return 0;
}
