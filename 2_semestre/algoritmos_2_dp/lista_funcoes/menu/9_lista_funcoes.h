void positivo_negativo(int n) 
  {
  printf("Insira um valor positivo ou negativo: ");
  scanf("%d", &n);

  if(n < 0) 
  {
  printf("%d NEGATIVO", n);
  }

  if(n > 0) 
    {
    printf("%d POSITIVO",n);
    }

  if(n == 0) 
    {
    printf("ZERO");
    }
  }
