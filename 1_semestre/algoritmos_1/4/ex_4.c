#include <stdio.h>
int main() 
{
	int n=0, i=0, r=0;

	printf("Digite o valor de n: ");
	scanf("%d", &n);

	while(i != n) 
	{
		i++;
		r = r + i;

		if(i == n) 
		{
			r = r/n;
			printf("A media da temperatura equivale a: %d\n", r);
		}
	}
	return 0;
}
