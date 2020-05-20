#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "color.h"
#include "tipos.h"
#include "servicios.h"
typedef struct
{
    int dia;
    int mes;
    int anio;

}Fecha;

typedef struct
{
    int idTrabajo; //Autoincremental
    int idMascota;
    int idServicio;
    Fecha fechaTrabajo;
    int precio;
    int ocupado;// 0=disponible

}Trabajo;

#endif // TRABAJOS_H_INCLUDED

void inicializarTrabajos(Trabajo trabajos[], int tamTrab);
int buscarLibreTrabajo(Trabajo trabajos[], int tamTrab);
int altaTrabajo(int proxIdTrab, Trabajo trabajos[], int tamTrab, int proxIdMasc, Mascota mascotas[], int tamasc, Tipo tipos[], int tamtipo,Color colores[], int tamcol, Servicio servicios[], int tamserv,Cliente clientes[],int tamcli);
