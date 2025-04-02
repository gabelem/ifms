#include <stdio.h>

int main() 
{
	int idade, peso;

	printf("Insira sua idade: ");
	scanf("%d", &idade);

	printf("Insira seu peso: ");
	scanf("%d", &peso);

	if(idade >= 18 && peso >= 50 && idade < 70) 
	{
		printf("Pode doar sangue");
	}
	else
	{
		printf("N pode doar sangue..");
	}
	return 0;
}
