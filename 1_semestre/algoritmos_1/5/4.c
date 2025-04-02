#include <stdio.h>
int main() 
{
	int num[10] = {20,40,60,80,100,110,125,120,360};
	int i;
	int maior[5];
	int menor[4];

	for(i=0; i < 6;i++) 
	{
		if( num[i] > 25) 
		{
			maior[i] = num[i];
		}
		printf("maior: %d\n", maior[i]);
	}
	printf("\n");
	for(i=0; i < 4;i++) 
	{
		if(num[i] < 85) 
		{
			menor[i] = num[i];
		}
		printf("menor: %d\n", menor[i]);
	}
}
