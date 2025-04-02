#include <stdio.h>
#define verde "\e[0;32m"
#define azul "\e[0;34m" 
#define vermelho "\e[0;31m"
int main() 
{
	int n[10], i, valor=0, soma_par=0, soma_impar=0;

	for(i=0; i < 10;i++) 
	{
		printf("Determine o valor de n: ");
		scanf("%d", &valor);
		n[i] = valor;
	}

	for(i=0; i < 10;i++) 
	{
		printf(verde"%d ", n[i]);
	}
	printf("\n");

	for(i=0; i < 10;i++) 
	{
	
		if((n[i] % 2) == 0)
		{
			soma_par = soma_par + n[i];
			printf(azul"PAR: %d\n", n[i]);

		}

		if((n[i] % 2) != 0) 
		{
			soma_impar = soma_impar + n[i];
			printf(vermelho"IMPAR: %d\n", n[i]);
		}
	}

	printf("\n");
	printf(azul"Soma dos pares: %d\n", soma_par);
	printf(vermelho"Soma dos impares: %d\n", soma_impar);
	
	return 0;
}
