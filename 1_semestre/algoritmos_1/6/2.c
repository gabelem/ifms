#include <stdio.h>
int main() 
{
	int oito[8], i;

	for(i=0; i < 8; i++) 
	{
		printf("Determine o valor de n: ");
		scanf("%d", &oito[i]);
	}
	for(i=0; i < 8; i++) 
	{
		if(oito[i] % 2 == 0) 
		{
			printf("\nMULTIPLO DE 2: %d\n", oito[i]);
		}
	}

	for(i=0; i < 8; i++) 
	{
		if(oito[i] % 3 == 0) 
		{
			printf("\nMULTIPLO DE 3: %d\n", oito[i]);
		}
	
	}
	for(i=0;i < 8; i++) 
	{
		if(oito[i] % 2 == 0 && oito[i] % 3 == 0) 
		{
			printf("\n MULTIPLO(S) DE 3 E 2: %d\n", oito[i]);
		}
	}
	return 0;
}
