#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "1_lista_funcoes.h"
#include "2_lista_funcoes.h"
#include "3_lista_funcoes.h"
#include "4_lista_funcoes.h"
#include "5_lista_funcoes.h"
#include "6_lista_funcoes.h"
//#include "7_lista_funcoes.h"
#include "8_lista_funcoes.h"
#include "9_lista_funcoes.h"
#include "10_lista_funcoes.h"
#include "11_lista_funcoes_c_ponteiros.h"
#include "12_lista_funcoes_c_vetor.h"
#include "13_lista_funcoes_triangulo.h"
#include "14_lista_funcoes_media_aritmetica.h"
#include "15_lista_funcoes_calcular_potencia.h"
#include "n_perfeito_par.h"


int main() 
  {
  int selecionar;

  
  do 
    {
    printf("\n[1] SAUDACAO  [2] TEXTO_POR_PARAMETRO  [3] RETORNA_OK\n");

    printf("\n[4] BHASKARA  [5] SEGUNDOS_PARA_HORAS [6] IDADE_PARA_ANO_MES_DIA\n");

    printf("\n[7] N_PERFEITO_PAR  [8] IDADE_DO_NADADOR_POR_PARAMETRO  [9] VALOR_POSITIVO_OU_NEGATIVO\n");

    printf("\n[10] VALOR_PAR_OU_IMPAR  [11] CONCEITO_DA_MEDIA  [12] VALORES_ORDENADOS\n");

    printf("\n[13] TRIANGULO  [14] MEDIA_ARITMETICA  [15] X_COM_POTENCIA_Z\n");


    printf("\nSelecione uma opcao ou digite 0 para sair: ");
    scanf("%d", &selecionar);
    
    
    if(selecionar == 1) 
      {
      saudacao();
      }


    if(selecionar == 2) 
      {
      char texto[15] = "Hello World.\n";
      texto_por_parametro(texto);
      }


    if(selecionar == 3) 
      {
      char texto2[100] = "Outro texto.\n";
      retorna_ok(texto2);
      return(printf("OK\n"));
      }


    //BHASKARA NAO FUNCIONA COM RESULTADO EM FRACAO! :(
    if(selecionar == 4) 
      {
      int a, b, c;
      bhaskara(a, b, c);
      }


    if(selecionar == 5) 
      {
      int segundos;
      float horas;
      segundos_para_horas(segundos);
      }

    
    if(selecionar == 6) 
      {
      int idade;
      receba(idade);
      }


    if(selecionar == 7) 
      {
      n_perfeito_par();
      }


    if(selecionar == 8) 
      {
      int idade;
      receber_categoria(idade);
      }


    if(selecionar == 9) 
      {
      int n;
      positivo_negativo(n);
      }

    if(selecionar == 10) 
      {
      verificar_par_impar();
      }


    if(selecionar == 11)
      {
      float nota;
      media(&nota);
      }

    if(selecionar == 12) 
      {
      int vetor[3];
      ordenar(vetor);
      }


    if(selecionar == 13) 
      {
      triangulo();
      }


    if(selecionar == 14) 
      {
      media_aritmetica();
      }


    if(selecionar == 15) 
      {
      int x, z;
      calcular_potencia(x,z);
      }

    }
    while(selecionar != 0);
  }
