#include <stdio.h>
int main() 
{
	int idade[5], i, valor=0, soma_18=0;

	for(i=0;i < 5;i++) 
	{
		printf("Insira o valor da idade da pessoa  %d: ", i);
		scanf("%d", &valor);
		idade[i] = valor;

		if(valor > 18) 
		{
			soma_18 = soma_18+idade[i];
		}

	}
	printf("Maiores de 18: %d", soma_18);
}
