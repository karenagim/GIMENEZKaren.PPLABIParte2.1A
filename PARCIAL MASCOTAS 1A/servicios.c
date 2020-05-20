#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

void mostrarServicios(Servicio servicios[], int tamserv)
{
    printf("_________________________________\n");
    printf(" -----LISTADO DE SERVICIOS-------\n");
    printf(" =====================================\n");
    printf("  ID_SERVICIO   DESCRIPCION    PRECIO  \n");
    printf("--------------------------------------\n");
    for(int i=0; i<tamserv; i++)
    {
       printf("%d ---->%-10s    -->$%6.2f \n", servicios[i].idServicio, servicios[i].descripcion,servicios[i].precio);

    }
}

//si existe el id servicio revela el precio
int buscarPrecioServPorId (int idABuscar, Servicio servicios[], int taserv)
{
    float precio = -1;
    for(int i=0; i<taserv; i++)
    {
        if(servicios[i].idServicio == idABuscar )
        {
            precio = servicios[i].precio;
            break;
        }
    }

    return precio;
}


int cargarDescripcionServicio(char descripcion[], int idserv, Servicio servicios[], int tamserv)
{
    int todoOk = 0;

    for(int i=0; i<tamserv; i++)
    {
        if(servicios[i].idServicio == idserv)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}

