#include <stdio.h>
int main() 
{
	int n=0, i, v=0;

	printf("Determine a quantia de n para imprimir e somar: ");
	scanf("%d", &n);

	for(i=0 ;i <= n;i++) 
	{
		v = v+i;
	}
	printf("A soma da seq da quantia de n equivale a: %d", v);
	return 0;
}
