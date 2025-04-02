#include <stdio.h>
int main () 
{
	int nat=0, resto=0, i, bin[10000];

	printf("Determine o valor de n (APENAS PARA 2 DIGITOS) : ");
	scanf("%d", &nat);
	resto = nat;

	for(i=0;i < 10000;i++) 
	{
		resto = nat%2;
		bin[i] = resto;
		nat = nat/2;
	}

	for(i=10000; i > 0; i--) 
	{
		printf("%d", bin[i-1]);
	}
}
