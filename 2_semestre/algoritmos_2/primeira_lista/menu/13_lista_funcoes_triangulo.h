int triangulo()
  {
  int a, b, c;

  printf("Valor 1: \n");
  scanf("%d", &a);

  printf("Valor 2: \n");
  scanf("%d", &b);

  printf("Valor 3: \n");
  scanf("%d", &c);

  printf("Valor 1: %d", a);
  printf("\nValor 2: %d", b);
  printf("\nValor 3: %d", c);
  printf("\n");

  if (((a > abs(b-c)) && (a < (b+c)) && (b > abs(a-c)) && (b < (a+c))) && ((c > abs(b-a)) && (c < (b+a))))
    {
    printf("\nCondicao VERDADEIRA para a existencia de um Triangulo.\n");
  
    if ((a==b && (a==c && b==c)))
      {
      printf("\nTriangulo EQUILATERO.\n");
      }
  
    if ((((a != b) && (a != c)) && (b != c)))
      {
      printf("\nTriangulo ESCALENO.\n");
      }
  
    if (((((a==b) && (b != c)) || ((b==c) && (a != b))) || ((a==c) && (b!=a))))
      {
      printf("\nTriangulo ISOSCELES.\n");
      }
    }
    
  else
    {
    printf("Condicao FALSA para a existencia de um Triangulo.\n");
    }

return (0);
  }
