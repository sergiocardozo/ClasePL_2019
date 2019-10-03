
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
# define QTY_EMPLEADOS 1000
int main()
{
    Employee eEmployee[QTY_EMPLEADOS];
    int opcion;
    int opcionInf;
    int order;
    int auxId = 1;

    initEmployees (eEmployee,QTY_EMPLEADOS);
    do
    {
        printf("1- ALTA EMPLEADOS. \n");
        printf("2- MODIFICAR EMPLEADOS \n");
        printf("3- BAJA EMPLEADOS \n");
        printf("4- INFORMES \n");
        printf("5- SALIR. \n");
        printf("------------------------------------------ \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        	printf("\n\tALTAS.");
        	getEmployee(eEmployee,QTY_EMPLEADOS);
            break;
        case 2:
        	if(!existEmployees(eEmployee,QTY_EMPLEADOS))
        	{
        		modifyEmployee(eEmployee,QTY_EMPLEADOS);
        	}
        	else
        	{
        		printf("Debe ingresar al menos un empleado para continuar \n");
        	}
        	break;
        case 3:
        	printEmployees(eEmployee,QTY_EMPLEADOS);
        	if(existEmployees(eEmployee,QTY_EMPLEADOS) == 0)
        	{
        		printf("Ingrese ID de empleado a eliminar: ");
                scanf("%d", &auxId);
                removeEmployee(eEmployee,QTY_EMPLEADOS,auxId);
        	}
        	else{
        		printf("Debe ingresar al menos un empleado para continuar \n");
        	}
        	break;
        case 4:
        	if(existEmployees(eEmployee,QTY_EMPLEADOS) == 0)
        	{
        		utn_getInt(&opcionInf,"Ingrese una opcion","ERROR. Opcion incorrecta",1,2,10);
        		switch(opcionInf)
        		{
        		case 1:
        			printf("\nElija tipo de orden de los empleados: \n");
        			printf("1- Ascendente \n");
        			printf("2- Descendente \n");
        			printf("------------------------------------------ \n");

        			scanf("%d", &order);

        			sortEmployees(eEmployee,QTY_EMPLEADOS,order);
        			printEmployees(eEmployee,QTY_EMPLEADOS);
        			break;
        		case 2:
        			averageEmployeesSalary (eEmployee, QTY_EMPLEADOS);
        			break;
        		}
        	}
        	else
        	{
        		printf("Debe ingresar al menos un empleado para continuar \n");
        	}
        	break;
        case 5:
            printf("Saliendo del programa. \n");
            break;
        default:
            printf("Opcion incorrecta \n");
        }

    }
    while (opcion!=5);

    return 0;
}
