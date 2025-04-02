#include <stdio.h>
int main()
{
	int n[10];
	int i, valor = 0;
	int maior=0, menor=0;

	for(i = 0;i < 10 ;i++) 
	{
		printf("Determine o valor de n: ");
		scanf("%d", &valor);
		n[i] = valor;
	}

	for(i = 0;i < 10;i++) 
	{
		if(n[i] > maior) 
		{
			maior = n[i];
		}

		if(n[i] < menor) 
		{
			menor = n[i];
		}
	}

	printf("Maior: %d\n", maior);
	printf("Menor: %d\n", menor);
	return 0;
}
