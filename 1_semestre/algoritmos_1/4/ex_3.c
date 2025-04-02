#include <stdio.h>
int main()
{
	int n=0, i=0, r=0;

	printf("Determine um valor para n: ");
	scanf("%d", &n);

	while(i != n) 
	{
		i++;
		r = i;
		if((r%2) != 0) 
		{
			printf("%d impar \n", r);
		}
	}
	return 0;
}
