/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustin
 Version     :
 Copyright   : GLP 3
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int calculoMaxYMin(int *flagFun,int numeroFun,int *MaxFun, int *MinFun);

int main(void)
{
	int numero;
	char respuesta;
	int Max = 0;
	int Min = 0;
	int flag = 0;

	do
	{
		//printf("\nIngrese un numero");
		//scanf("%d",&numero);
		getNumero(&numero,0,100,3,"Numero:","error");
		calculoMaxYMin(&flag,numero,&Max,&Min);
		printf("\nDesea continuar? s/n");
		scanf("%c",&respuesta);

	} while(respuesta != 'n');

	printf("El Maximo es %d ",Max);
	printf("El Minimo es %d ",Min);


}

int calculoMaxYMin(int* pFlag,int numeroFun,
				   int* pMax,int* pMin)
{
	int max = *pMax;
	int min = *pMin;
	int flag = *pFlag;


	//pregunto si es la primera vez que entro
	if(flag==0)
	{
		max = numeroFun;
		min = numeroFun;
		*pFlag=1; // paso el flag externo a 1
	}


	if(numeroFun > max)
	{
		max = numeroFun;
	}
	*pMax = max;


	if(numeroFun < min)
	{
		min = numeroFun;
	}
	*pMin = min;


	return 0;
}

int getNumero(int* pNumero,int maximo,int minimo,int reintentos,char* pMensaje, char* pMensajeError)
{
	int num,i;
	int ret = -1; //cargo con error por default
	// pedido
	for(i=0;i<reintentos;i++)
	{
	printf("%s",pMensaje);
	scanf("%d",&num);

	//validacion
		if(num >= minimo && num<=maximo)
		{
		//el numero esta bien
		*pNumero = num;
		ret = 0;
		break; //termina la funcion interrumpe la funcion del bucle
		}
		else{
			printf("%s",pMensajeError);
		}

	}
return ret;
}


