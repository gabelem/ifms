#include <stdio.h>
int main() 
{
	int A[8], i, mais=0, menos=0;

	for(i=0; i < 8;i++) 
	{
		printf("Determine o valor de n: ");
		scanf("%d", &A[i]);
	}	
	for(i=0; i < 8;i++) 
	{
	if(A[i] > mais) 
	  {
	  mais = A[i];
	  }
	}
	printf("Maior valor: %d", mais);
	return 0;
}
