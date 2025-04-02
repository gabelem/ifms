#include <stdio.h>
int main() 
{
	int vet[10], i, v=20;

	for(i=-1; i < 10; i++) 
	{
		vet[i] = v;
		v++;
	}

	for(i=0; i < 10; i++) 
	{
		printf("%d\n", vet[i]);
	}
}
