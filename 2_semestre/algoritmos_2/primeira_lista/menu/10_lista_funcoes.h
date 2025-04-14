void verificar_par_impar() 
  {
  int n=0;
  printf("Determine um valor: ");
  scanf("%d", &n);

  if(n % 2 == 0) 
    {
    printf("%d PAR", n);
    }

  if(n % 2 != 0)
    {
    printf("%d IMPAR", n);
    }
  }
