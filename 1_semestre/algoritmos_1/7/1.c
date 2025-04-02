#include <stdio.h>
int main() 
{
	int M[5][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}, i;
	
	
	
	int a=0;
	for(i=0; i < 5;i++) 
	{
		printf("%d ",M[3][i]);
	}

	printf("\n\n");
	for(i=0; i < 5;i++) 
	{
		a = a + M[3][i];
		printf("Soma LINHA 4: %d\n", a);	
	}
	printf("\n");

	
	
	int b=0;
	for(i=0; i < 5;i++) 
	{
		printf("%d ",M[i][2]);
	}

	printf("\n\n");
	for(i=0; i < 5;i++) 
	{
		b = b + M[i][2];
		printf("Soma COLUNA 2: %d\n", b);	
	}
	printf("\n");

	
	
	int c=0;
	for(i=0; i < 5;i++) 
	{
		printf("%d ",M[i][i]);
	}

	printf("\n\n");
	for(i=0; i < 5;i++) 
	{
		c = c + M[i][i];
		printf("Soma DIAGONAL PRINCIPAL: %d\n", c);	
	}

	
	int d=0;
	int j=0;
	for(i=0; i < 5;i++) 
	{
		for(j=0; j <5;j++) 
		{
			d = d+ M[i][j];
			printf("%d ", M[i][j]);
		}
		printf("\n%d ", c);
	}
}
