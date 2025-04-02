#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() 
{
	int gen,idade;

	printf("Digite (1) para Masculino ou (2) para Feminino: ");
	scanf("%d", &gen);

	printf("Digite sua idade: ");
	scanf("%d", &idade);

	if(gen == 1 && idade >= 18) 
	{
		printf("Apto ao alistamento");
	}

	else 
	{
		printf("Não apto.");
	}
}
