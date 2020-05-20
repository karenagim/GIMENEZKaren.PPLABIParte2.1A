#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"


int cargarDescripcionTipo(char descripcion[], int idTipo, Tipo tipos[], int tamTipo)
{
    int todoOk = 0;

    for(int i=0; i<tamTipo; i++)
    {
        if(tipos[i].idTipo == idTipo)
        {
            strcpy(descripcion, tipos[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}


void mostrarTiposMascotas(Tipo tipos[], int tamtipo)
{
    printf("______________________________________\n");
    printf(" -----LISTADO DE TIPOS DE MASCOTAS----\n");
    printf(" =====================================\n");
    printf("  ID_TIPO     Descripcion  \n");
    printf("---------------------------------\n");
    for(int i=0; i<tamtipo; i++)
    {
       printf(" %d ===>%10s\n", tipos[i].idTipo, tipos[i].descripcion);

    }
}

