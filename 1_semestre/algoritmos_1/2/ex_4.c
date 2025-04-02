#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	int entrada;


	printf("Insira um valor: ");
	scanf("%d", &entrada);


	if(entrada % 2 == 0) 
	{
		printf("O QUADRADO do número PAR %d é %d", entrada ,(entrada*entrada));
	}
	
	else 
	{
		printf("O número NÃO é PAR...");
	}


	return 0;
}
