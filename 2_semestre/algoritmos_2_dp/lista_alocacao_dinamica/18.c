#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void func(int tamanho ,int A[tamanho][tamanho], int B[tamanho][tamanho])
{
  int **C;
  C = (int **) malloc(tamanho * sizeof(int *));

  for(int k = 0; k < tamanho; k++)
  {
    C[k] = malloc(sizeof(int));
  }

  if(C == NULL)
  {
    printf("erro ao alocar\n");
  }

  printf("\n");
  printf("resultado da multiplicacao: ");
  for(int coluna = 0; coluna < tamanho; coluna++)
  {
    for(int linha = 0; linha < tamanho; linha++)
    {
      C[linha][coluna] = (A[linha][coluna] * B[linha][coluna]);
    }
  }

  for(int x = 0; x < tamanho; x++)
  {
    for(int y = 0; y < tamanho; y++)
    {
      printf("%d ", C[x][y]);
    }
  }

  printf("\n");

  for(int z = 0; z < tamanho; z++)
  {
    free(C[z]);
  }
  free(C);
}

int main()
{
  int N;
  printf("Determine o valor de N: ");
  scanf("%d", &N);

  srand(time(NULL));

  int vetor1[N][N], vetor2[N][N];

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      vetor1[i][j] = rand() % 3 + 1;
      vetor2[i][j] = rand() % 3 + 1;
    }
  }

  printf("primeiro vetor: \n");
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      printf("%d ", vetor1[i][j]);
    }
  }

  printf("\nsegundo vetor: \n");

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      printf("%d ", vetor2[i][j]);
    }
  }

  func(N, vetor1, vetor2);
  return 0;
}
