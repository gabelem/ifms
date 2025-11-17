#include <stdio.h>

int main()

{
  int n, i, j;
  int count = 0;
  int num = 0;

  scanf("%d %d %d", &n, &i, &j);

  while(count < n)
  {
  if(num % i == 0 || num % j == 0)
    {
    printf("%d ", num);
    count++;
    }
    num++;
    }

    return 0;
}

