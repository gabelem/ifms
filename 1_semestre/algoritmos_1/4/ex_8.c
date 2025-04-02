#include <stdio.h>
int main() 
{
	int n[5],i, r=0;

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	n[4] = 0;
	n[5] = 0;

	for(i=0; i != 6;i++) 
	{
		r++;
		n[i] = r;
	}
	
	for(i=0; i != 6;i++) 
	{
		printf("%d ", n[i]);
	}

	for(i=0; i != 5;i++) 
	{
		i++;
		r = r*i;
		i--;
	}
	printf("%d", r);
}
