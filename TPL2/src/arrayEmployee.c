/*
 * arrayEmployee.c
 *
 *  Created on: 2 oct. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployee.h"
#include "utn.h"

int initEmployees (sEmployee list[], int len)
{

    int ret = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        ret = 0;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = 0;
            list[i].isEmpty = 0;
            list[i].id = 0;
        }
    }
    return ret;
}

int findEmptySpace (sEmployee list[], int len)
{
    int ret = -1;
    int i;

    for (i=1; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int existEmployees(sEmployee list[], int len)
{
    int i;

    for( i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            return 0;
        }
    }
    return -1;
}

int addEmployee (sEmployee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
    list[id].id = id;
    strcpy(list[id].name, name);
    strcpy(list[id].lastName, lastName);
    list[id].salary = salary;
    list[id].sector = sector;
    list[id].isEmpty = 1;
    return id;
}

int modifyEmployee (sEmployee list[], int len)
{
    int ret = -1;
    int modify;
    int findEmployee;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;
    int id;
    char seguir = 's';

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
            printf("------------------------------------------ \n");
            scanf("%d", &modify);

            switch(modify)
            {
            case 1:
                getValidString("Ingrese nuevo nombre: ", "Error, ingrese solo letras: ", newName);
                strcpy(list[findEmployee].name, newName);
                break;
            case 2:
                getValidString("Ingrese nuevo apellido: ", "Error, ingrese solo letras: ", newLastName);
                strcpy(list[findEmployee].lastName, newLastName);
                break;
            case 3:
                newSalary = getValidFloat("Ingrese nuevo salario: ", "Error, ingrese solo numeros: ", 0, 10000000);
                list[findEmployee].salary = newSalary;
                break;
            case 4:
                newSector = getValidInt("Ingrese nuevo sector: ", "Error, ingrese solo numeros: ", 1, 1000);
                list[findEmployee].sector = newSector;
                break;
            default:
                printf("Ingrese una opcion del 1 al 4: ");
            }
            printf("\250Desea continuar? s/n :");
            setbuf(stdin, NULL);
            scanf("%c", &seguir);
        }
        while (seguir == 's');

        printf("Empleado modificado \n");
    }
    else
    {
        printf("No se encontro empleado con ese ID \n");
    }
   return ret;
}

int findEmployeeById(sEmployee list[], int len, int id)
{
    int ret = -1;
    int i;

    if (list != NULL && len > 0)
    {
        for (i=1; i<len; i++)
        {
            if (list[i].isEmpty == 1 && list[i].id == id)
            {
                return i;
            }
        }
    }
    return ret;
}

int removeEmployee (sEmployee list[], int len, int employeeId)
{
    int findEmployee;

    findEmployee = findEmployeeById(list, len, employeeId);

    if (findEmployee > 0)
    {
        list[findEmployee].isEmpty = DELETED;
        printf("Empleado eliminado con exito \n");
    }
    else
    {
        printf("No se ha encontrado empleado con ese ID \n");
    }

    return findEmployee;
}

int printEmployees (sEmployee list[], int len)
{
    int index = -1;
    int i;

    if(len > 0)
    {
        printf("ID\tNombre\t\tApellido\t\tSalario\t\tSector \n");

        for(i=0; i<len; i++)
        {
            if (list[i].isEmpty == 1)
            {
                setbuf(stdin, NULL);
                printf("%d\t%s\t\t%s\t\t\t%.2f\t\t%d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        index = 0;
    }
    return index;
}

int sortEmployeeByName(sEmployee list[], int len, int order)
{
    int index = -1;

    sEmployee auxiliar;

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
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                            else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
                            {
                                auxiliar = list[i];
                                list[i] = list[j];
                                list[j] = auxiliar;
                            }
                        }
                    }
                index = 0;
                break;
            case 2:
                for(int i = 0; i < len - 1; i++)
                {
                    for(int j = i + 1; j < len; j++)
                    {
                        if(strcmp(list[j].lastName, list[i].lastName) > 0)
                        {
                            auxiliar = list[i];
                            list[i] = list[j];
                            list[j] = auxiliar;
                        }
                        else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
                        {
                            auxiliar = list[i];
                            list[i] = list[j];
                            list[j] = auxiliar;
                        }
                    }
                }
                index = 0;
                break;
            default:
                printf("Ingrese 1 para ascendente o 2 para descendente \n");
            }
        }
    }
    return index;
}

void averageEmployeesSalary (sEmployee list[], int len)
{
    float average = 0;
    float total = 0;
    int employeeCounter = 0;
    int salaryGreaterThanAverage = 0;
    int i;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            employeeCounter ++;
            total = total + list[i].salary;
        }
    }
    average = total / employeeCounter ;

    for (i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1 && list[i].salary >average)
        {
            salaryGreaterThanAverage ++;
        }
    }

    printf("Total de salarios: %.2f \n", total);
    printf("Promedio de salarios: %.2f \n", average);
    printf("Cantidad de empleados con salario mayor al promedio: %d \n", salaryGreaterThanAverage);

}



