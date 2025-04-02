#include <stdio.h>
int main() 
{
	int n=5, i, m=0, r=0;

	for(i=0; i < n; i++) 
	{
		m = m+(1*i);
		printf("%d\n", m);
	}

	r = m/n;
	printf("Resultado: %d\n", r);
	return 0;
}
