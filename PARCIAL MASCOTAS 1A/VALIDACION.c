#ifndef VALIDACION_C_INCLUDED
#define VALIDACION_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "VALIDACION.h"

int getInt(char message[], char messageError[], int limiteMin, int limiteMax)
{
    int numero1;

    printf("%s", message);
    scanf("%d", &numero1);
    while(numero1 < limiteMin || numero1 > limiteMax)
    {
        printf("%s", messageError);
        scanf("%d", &numero1);
    }

    return numero1;
}


void getString(char str[], int limitChar, char message[], char messageError[])
{
    printf("%s", message);
    fflush(stdin);
    fgets(str, limitChar, stdin);
    str[strlen(str)-1] = '\0';
    while(strlen(str) >= limitChar - 2 || strlen(str) == 0)
    {
        printf("%s", messageError);
        fflush(stdin);
        fgets(str, limitChar, stdin);
        str[strlen(str)-1] = '\0';
    }
}

void strLwr(char str[])
{
    int i = 0;

    while (str[i] != '\0')
	{
    	if (str[i] >= 'A' && str[i] <= 'Z') {
        	str[i] = str[i] + 32;
    	}
      	i++;
	}
}

#endif // VALIDACION_C_INCLUDED
