#include <stdio.h>
int main() 
{
	int n=0, x=0, i=1, p=0;

	printf("Determine o valor de n: ");
	scanf("%d", &n);

	printf("Determine o valor de x: ");
	scanf("%d", &x);

	p=n;
	while(i != x) 
	{
		i++;
		n= n*p;
		
		printf("A potencia de %d elevado a %d equivale a: %d \n", p, i, n);
	}
	return 0;
}
