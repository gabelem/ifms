#include <stdio.h>
int main() 
{
	float A[6], B[6];
	int i;

	int VA=0, VB=0;

	int SA=0, SB=0;

	int RESULTADO=0;

	for(i=0; i < 6;i++) 
	{
		printf("Determine o valor do vetor A: ");
		scanf("%d", &VA);
		A[i] = VA;
		SA= SA+VA;
		printf("%d\n",A[i]);
		printf("Soma A: \n%d\n",SA);
	}

	for(i=0; i < 6;i++) 
	{
		printf("Determine o valor do vetor B: ");
		scanf("%d", &VB);
		B[i] = VB;
		SB= SB+VB;
		printf("%d\n", B[i]);
		printf("Soma B: \n%d\n", SB);
	}

	for(i=0; i < 6;i++) 
	{
		if(i == 5) 
		{
			RESULTADO = (SA+SB);
			printf("SOMATORIA: %d\n", RESULTADO);
			A[i] = RESULTADO;
			printf("A[0]= %d\n", (int)A[i]);
		}
	}
}
