#include <stdio.h>
int main() 
{
	int A[20], i, dobro=0, v=5;
	int B[20], recebe=0;
	
	for(i=0; i < 20 ; i++) 
	{
		A[i] = v;
		v++;
		printf("%d ", A[i]);
		B[i] = A[i] * 2;
	}
	printf("\n");
	for(i=0; i < 20 ; i++) 
	{
		printf("%d ", B[i]);
	}
	printf("\n");
}
