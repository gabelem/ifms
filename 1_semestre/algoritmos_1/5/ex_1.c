#include <stdio.h>
int main() 
{
	int n=0, i=0;
	float resultado=0;

	printf("Determine o valor n: ");
	scanf("%d", &n);

	while(i < n)
	{
		i++;
		resultado = resultado + ((float)1/(float)i); /*pode ser tbm resultado += */
		printf("%f ", resultado);
	}
}
