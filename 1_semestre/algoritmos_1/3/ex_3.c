#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
	int d,m;

	printf("Insira o dia do seu nascimento: ");
	scanf("%d", &d);

	printf("Insira o mês do seu nascimento: ");
	scanf("%d", &m);

	if(d > 31 || m > 12 || d <= 0 || m <= 0) 
	{
		printf("Não existe.");
	} 
	
	else 
	{
		printf("%d/%d", d, m);
	}
}
