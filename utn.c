/*
 * utn.c
 *
 *  Created on: 29 ago. 2019
 *      Author: alumno
 */

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
/*
  #define MSG_EDAD "ingrese edad:
  #define MSG_DNI "ingrese dni:
  #define MSG_ERR "nah esta mal.\n

 int main()
 	 int edad;
 	 int dni;
 	 int ok;

 	 char*t = "hola";
 	 printf(t);
 ok = int getNumero(&edad,120,1,5, msg_edad,msg_error);
 	 if(ok==0)
 	 {
 	 printf("edad correcta,");
 int getNumero(&dni,50000000,4000000,MSG_DNI,MSG_ERROR)


*/
