#include <stdio.h>
int main() 
{
	int n=0, i=0, resultado=0;

	printf("Determine o valor de n:\n");
	scanf("%d", &n);

	while(i != n) 
	{
		i++;
		resultado = resultado+i;
		printf("O valor sequencial de %d equivale a %d\n",i, resultado);
	}

	return 0;
}
