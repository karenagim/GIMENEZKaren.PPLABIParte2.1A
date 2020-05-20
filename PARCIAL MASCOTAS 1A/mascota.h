
#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "color.h"
#include "tipos.h"
#include "servicios.h"
#include "cliente.h"


//ESTRUCTURAS

typedef struct
{
    int idMascota;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int idDuenio; //Cliente fk
    int activo;// isEmpty

}Mascota;



void inicializarMascota(Mascota mascotas[], int tamMascota);
void harcodearMascota(Mascota mascotas[], int tamMascota);
void mostrarMascota(Mascota mascota,Tipo tipos[],int tamTipo,Color colores[],int tamcol,Cliente clientes[],int tamcli);
void mostrarMascotas(Mascota mascotas[], int tamasc,Tipo tipos[],int tamTipo,Color colores[],int tamcol,Cliente clientes[],int tamcli );

int altaMascota(int proxId,Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo,Color colores[],int tamcol );
int buscarMascota (int idABuscar, Mascota mascotas[], int tamasc);


void modificarMascota(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol,Cliente clientes[],int tamcli );


#endif // MASCOTA_H_INCLUDED

