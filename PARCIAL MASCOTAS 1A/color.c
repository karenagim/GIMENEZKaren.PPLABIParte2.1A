#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int cargarNombreColor(char nombre[], int idCol, Color colores[], int tamcol)
{
    int todoOk = 0;

    for(int i=0; i<tamcol; i++)
    {
        if(colores[i].idColor == idCol)
        {
            strcpy(nombre, colores[i].nombreColor);
            todoOk = 1;
        }
    }
    return todoOk;
}


void mostrarColoresMascotas(Color colores[], int tamcol)
{
    printf("__________________________________\n");
    printf(" -------LISTADO DE COLORES--------\n");
    printf(" ================================\n");
    printf("  ID_COLOR     Descripcion  \n");
    printf("----------------------------\n");
    for(int i=0; i<tamcol; i++)
    {
       printf(" %d ===>%10s\n", colores[i].idColor, colores[i].nombreColor);

    }
}

