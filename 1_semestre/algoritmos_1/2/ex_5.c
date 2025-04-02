#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define circuito_eletrico main


void circuito_eletrico()
{
	int p,v,i,r;

	printf("Insira o valor da Tensão(V): ");
	scanf("%d", &v);

	printf("Insira o valor da Corrente(I): ");
	scanf("%d", &i);

	printf("Insira o valor da Resistência(R): ");
	scanf("%d", &r);

	if( v==0 && r!=0 && i!=0 ) 
	{
		printf("Fórmula: P=R*I² \nP=%d(%d)² \nP= %dW\n", r, i ,r*(i*i) );
	}


	if( i==0 && v!=0 && r!=0 )
	{
		printf("Fórmula: P=V²/R \nP=%d²/%d \nP= %dW\n", v, r, ( (v*v)/r ) );
	}


	if( r==0 && v!=0 && i!=0 ) 
	{
		printf("Fórmula P=V*I \nP=%d*%d \nP= %dW\n", v,i, (v*i));
	}
}
