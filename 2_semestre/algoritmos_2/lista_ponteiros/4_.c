#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
  {
  float matriz[3][3];

  srand(time(NULL));

  for(int i = 0; i < 4; i++)
    {
    for(int j = 0; j < 4; j++) 
      {
      matriz[i][j] = rand() % 101;
      }
    }

  for(int i = 0; i < 4; i++) 
    {
    for(int j = 0 ; j < 4; j++) 
      {
      printf("[%d][%d] %p\n",  i , j, matriz[i][j]);
      }
    }
    printf("\n");
  }
