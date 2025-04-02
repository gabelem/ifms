#include <stdio.h>
int main()
{
	int num = 0;
	int save = 0;
	printf("Determine o n da sequencia: \n");
	scanf("%d", &num);

	while(num != 0)
	{
		printf("O quadrado de %d fica: %d \n", num, (num*num));
		num = num-1;
	}

	return 0;
}
