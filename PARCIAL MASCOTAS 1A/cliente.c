#include "mascota.h"
#include "cliente.h"


int cargarDescripcionNombreDuenio(char nombreDuenio[], int idDuenio,Cliente clientes[], int tamcli)
{
    int todoOk = 0;

    for(int i=0; i<tamcli; i++)
    {
        if(clientes[i].idCliente == idDuenio)
        {
            strcpy(nombreDuenio, clientes[i].nombreC);
            todoOk = 1;
        }
    }
    return todoOk;
}
