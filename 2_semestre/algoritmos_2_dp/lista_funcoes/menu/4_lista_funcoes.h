void bhaskara(int a, int b, int c) 
  {
  printf("Insira os valores para a b c: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("\na=%d b=%d c=%d",a, b, c);

  //delta
  printf("\nDelta= %d", ((b*b)-4*(a*c)));

  //bhaskara
  int positivo=((-1*(b)+sqrt((b*b)-4*(a*c)))/(2*a));
  
  int negativo=((-1*(b)-sqrt((b*b)-4*(a*c)))/(2*a));

  printf("\nBhaskara (+) = %d", positivo);
  
  printf("\nBhaskara (-) = %d\n", negativo);
  }
