#include <stdio.h>
int main() 
{
	int i;
	int l[10] = {1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 6000};
	int p[8] = {1010, 1505, 2040, 2550, 2000, 3500, 4000, 6000};

	int mesmo_curso[10];

	printf("RA'S dos alunos de LOGICA:");
	for(i=0; i < 10;i++)
	{
		printf("%d / ", l[i]);
	}
	
	printf("\n\nRA`s dos alunos de PROGRAMACAO:");
	for(i=0; i < 10;i++)
	{
		printf("%d / ",p[i]);
	}
	printf("\n");


	for(i=0;i < 10;i++) 
	{
		if(p[i] == l[i] && p[i] != 0 || l[i] != 0) 
		{
			mesmo_curso[i] = p[i];
		}
	}
	printf("\n\n");
	
	/*
	for(i=0; i < 10;i++) 
	{
	printf("RA's cursando o mesmo curso: %d, ", mesmo_curso[i]);
	}
	printf("\n");
	*/
}
