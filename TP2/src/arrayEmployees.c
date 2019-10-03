/*
 * arrayEmployees.c
 *
 *  Created on: 1 oct. 2019
 *      Author: sergio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

static int idGen(void)
{
	static int idMax=0;
	return idMax++;
}

int initEmployees (Employee* list, int len)
{

    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
        	list[i].id=0;
        	list[i].isEmpty = 1;
        	strcpy(list[i].name,"");
        	strcpy(list[i].lastName,"");
        	list[i].salary=0;
        	list[i].sector=0;
            ret = 0;
        }
    }
    return ret;
}

int findEmptySpace (Employee* list, int len,int* pPosicion)
{
    int ret = -1;
    int i;
    if(list!= NULL && len>=0 && pPosicion!=NULL)
    {
    for (i=1; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
        	ret = 0;
            *pPosicion = i;
            break;
        }
    }
    }
    return ret;
}

int existEmployees(Employee* list, int len)
{
    int i;
    int ret = -1;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}

int addEmployee (Employee* list,
							int len,
							int id,
							char name[],
							char lastName[],
							float salary,
							int sector)
{
	int i;
	int ret= -1;


	if(list!=NULL&&len>0)
	{
		i=findEmptySpace(list,len,&i);
		if(i>=0)
		{
			list[i].id = id;
			list[i].isEmpty=0;
			strncpy(list[i].name,name,sizeof(list[0].name));
			strncpy(list[i].lastName,lastName,sizeof(list[0].lastName));
			list[i].salary=salary;
			list[i].sector=sector;

			ret=0;
		}
		else
		{
			printf("\nNo hay espacio libre");
		}
	}
	return ret;
}

int getEmployee(Employee* list,int len)
{
	int ret=-1;

	int posicion;
	char bufferName[51];
	char bufferLastname[51];
	float bufferSalary;
	int bufferSector;
	int freeIndex=findEmptySpace(list,len,&posicion);

	if( !utn_getName(bufferName,51,"\nIngrese nombre: ","\nValor invalido",3,50,10)&&
			!utn_getName(bufferLastname,50,"\nIngrese apellido: ","\nValor invalido",3,50,10)&&
	        !utn_getFloat(&bufferSalary,"\nIngrese salario: ","\nValor invalido",0,32000000,10)&&
	        !utn_getInt(&bufferSector,"\nIngrese sector: ","\nValor invalido",1,1000,10)&&
	        freeIndex>=0)
	{
		addEmployee(list,len,idGen(),bufferName,bufferLastname,bufferSalary,bufferSector);
		ret=0;
	}
	return ret;

}

int modifyEmployee (Employee* list, int len)
{
    int ret = -1;
    int modify;
    int findEmployee;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;
    int id;

    printEmployees(list,len);
    printf("Ingrese ID de empleado a modificar: ");
    scanf("%d", &id);

    findEmployee = findEmployeeById(list, len, id);

    if (findEmployee > 0)
    {
        do
        {
            printf("\250Que desea modificar? \n");
            printf("1- Nombre \n");
            printf("2- Apellido \n");
            printf("3- Salario \n");
            printf("4- Sector \n");
            printf("5- Dejar de modificar");
            printf("------------------------------------------ \n");
            scanf("%d", &modify);

            switch(modify)
            {
            case 1:
            	utn_getName(list[findEmployee].name,51,"Ingrese nuevo nombre: ", "Error, ingrese solo letras: ",0,50,2);
                strcpy(list[findEmployee].name, newName);
                break;
            case 2:
            	utn_getName(list[findEmployee].lastName,51,"Ingrese nuevo nombre: ", "Error, ingrese solo letras: ",0,50,2);
                strcpy(list[findEmployee].lastName, newLastName);
                break;
            case 3:
            	newSalary = utn_getFloat(&list[findEmployee].salary,"Salario del empleado: ", "Error, ingrese solo numero flotante: ",0,32000000,2);
            	list[findEmployee].salary = newSalary;
                break;
            case 4:
            	newSector = utn_getInt(&list[findEmployee].sector,"Sector del empleado: ", "Error, ingrese solo numero: ",1,1000,2);
                list[findEmployee].sector = newSector;
                break;
            case 5:
            	break;
            default:
                printf("Ingrese una opcion del 1 al 4: ");
            }

        }
        while (modify != 5);

        printf("Empleado modificado \n");
    }
    else
    {
        printf("No se encontro empleado con ese ID \n");
    }
   return ret;
}

int findEmployeeById(Employee* list, int len, int id)
{
    int ret = -1;
    int i;

    if (list != NULL && len > 0)
    {
        for (i=1; i<len; i++)
        {
            if (list[i].id == id && list[i].isEmpty == 1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int removeEmployee (Employee* list, int len, int id)
{
	int index;
	    int ret= -1;
	    index=findEmployeeById(list,len,id);
	    if(list!=NULL && len>0 && index>=0)
	    {
	        list[index].id=0;
	        list[index].isEmpty = 1;
	        strcpy(list[index].name,"");
	        list[index].salary=0;
	        list[index].sector=0;
	        ret=0;
	    }
	    return ret;
}

int getDeleteEmployee(Employee *list,int len)
{
    int ret=-1;
    int auxId;
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,9999,10);
    if(findEmployeeById(list,len,auxId)== -1)
    {
    	printf("\nId invalido");
    }
    else
    {
    	removeEmployee(list,len,auxId);
    	        ret=0;

    }
    return ret;
}

int printEmployees (Employee* list, int length)
{
	int i;
	int ret= -1;
	if(list!=NULL && length>0)
	{
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty!=0)
			{
				printf("id: %d\n1. Name: %s\n2. Lastname: %s\n3. Salary %.2f\n4. Sector: %d\n", list[i].id,
	                                                                                                list[i].name,
																									list[i].lastName,
	                                                                                                list[i].salary,
	                                                                                                list[i].sector);
			}

		}
	}
	return ret;
}

int sortEmployees(Employee list[], int len, int order)
{
    int ret = -1;

    Employee buffer;

    if(len > 0 && list != NULL)
    {
        switch(order)
        {
            case 1:
                if(len > 0 && list != NULL)
                {
                    for(int i=0; i<len - 1; i++)
                    {
                        for(int j=i+1; j<len; j++)
                        {
                            if(strcmp(list[j].lastName, list[i].lastName) < 0)
                            {
                                buffer = list[i];
                                list[i] = list[j];
                                list[j] = buffer;
                            }
                            else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
                            {
                                buffer = list[i];
                                list[i] = list[j];
                                list[j] = buffer;
                            }
                        }
                    }
                ret = 0;
                break;
            case 2:
                for(int i = 0; i < len - 1; i++)
                {
                    for(int j = i + 1; j < len; j++)
                    {
                        if(strcmp(list[j].lastName, list[i].lastName) > 0)
                        {
                            buffer = list[i];
                            list[i] = list[j];
                            list[j] = buffer;
                        }
                        else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
                        {
                            buffer = list[i];
                            list[i] = list[j];
                            list[j] = buffer;
                        }
                    }
                }
                ret = 0;
                break;
            default:
                printf("Ingrese 1 para ascendente o 2 para descendente \n");
            }
        }
    }
    return ret;
}

void averageEmployeesSalary (Employee* list, int len)
{
    float promedio = 0;
    float total = 0;
    int contador = 0;
    int salaryGreaterThanAverage = 0;
    int i;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            contador ++;
            total = total + list[i].salary;
        }
    }
    promedio = total / contador ;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].salary > promedio)
        {
            salaryGreaterThanAverage ++;
        }
    }

    printf("Total de salarios: %.2f \n", total);
    printf("Promedio de salarios: %.2f \n", promedio);
    printf("Cantidad de empleados con salario mayor al promedio: %d \n", salaryGreaterThanAverage);

}
