void ordenar(int vetor[3]) 
  {
  printf("Determine os valores a b c para o vetor: ");
  scanf("%d %d %d", &vetor[0],&vetor[1],&vetor[2]);

  int i, j, aux;
  for(i = (3-1); i >= 1;i--) 
    {
    for(j=0; j < i ;j++) 
      {
      if(vetor[j] > vetor[j+1]) 
        {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
        }
      }
    }
    printf("%d %d %d\n", vetor[0],vetor[1],vetor[2]);
  }
