#include <stdio.h>
int main() 
{
	int vetor[6] = {4,5,2,3,1};
	int i;
	int j;
	int aux;
	int crescente;

	for(i= 6-1; i >= 1; i--) 
	{
		for(j=0 ; j < i; j++) 
		{
			if(vetor[j]>vetor[j+1]) 
			{
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
		printf("Ordem decrescente: %d\n", vetor[j]);
	}
	printf("\n");
	
	for(i=0; i < 6; i++) 
	{
	if( vetor[i] > crescente) 
	{
	crescente = vetor[i];
	printf("Ordem crescente %d\n", vetor[i]);
	}
	}
	return 0;
	}
