#include <stdio.h>
int main() 
{
	int n[6], i, valor=0, par=0, impar=0, n_par=0, n_impar=0;

	for(i=0; i < 6; i++) 
	{
		printf("Determine o valor de n: ");
		scanf("%d", &valor);
		n[i] = valor;
	}

	for(i=0; i < 6;i++) 
	{
		if(n[i] % 2 == 0) 
		{
			n_par++;
			par = n[i];
			printf("Par: %d\n", n[i]);
		}

		if(n[i] % 2 != 0) 
		{
			n_impar++;
			impar = n[i];
			printf("Impar: %d\n", n[i]);
		}
	}
		printf("\nQuantia de pares= %d e Quantia de impares %d\n", n_par, n_impar);
}
