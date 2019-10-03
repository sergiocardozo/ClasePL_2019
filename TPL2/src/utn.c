/*
 * utn.c
 *
 *  Created on: 2 oct. 2019
 *      Author: sergio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployee.h"
#include "utn.h"
void getString (char message[], char input[])
{
    printf("%s",message);
    scanf ("%s", input);
}

char getChar(char message[])
{
    char auxiliar;

    printf("%s",message);
    setbuf(stdin, NULL);
    scanf("%c",&auxiliar);

    return auxiliar;
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{
    while(1)
    {
        if (!getStringLetters(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

int getStringLetters(char message[],char input[])
{
    char aux[256];

    getString(message, aux);

    if(isOnlyLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isOnlyLetters(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];

    float auxFloat;

    while(1)
    {
        if (!getStringFloatNumbers(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        auxFloat = atof(auxStr);

        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}

int getStringFloatNumbers(char message[],char input[])
{
    char aux[256];

    getString(message, aux);

    if(isNumericFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isNumericFloat(char str[])
{
    int i=0;

    int pointCounter = 0;

    while(str[i] != '\0')
    {
        if (str[i] == '.' && pointCounter == 0)
        {
            pointCounter++;
            i++;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }

        i++;
    }
    return 1;
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];

    int auxInt;

    while(1)
    {
        if (!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}

int getStringNumbers(char message[],char input[])
{
    char aux[256];

    getString(message,aux);

    if(isNumeric(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isNumeric(char str[])
{
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void cleanStdin(void)
{
    int c;

    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}
