#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "mascota.h"
#include "color.h"
#include "tipos.h"
#include "servicios.h"


#endif // INFORMES_H_INCLUDED
void informarlistadeMascotasPorColor(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo[], Color colores[],int tamcol,Cliente clientes[],int tamcli);
void listaMascotasPorTipoYNombre(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol,Cliente clientes[],int tamcli);
void informarlistadeMascotasPorMenorEdad(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo[], Color colores[],int tamcol, Cliente clientes[],int tamcli);
void informarMascotasPorTipo(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo[], Color colores[],int tamcol, Cliente clientes[],int tamcli);
void informarMascotasPorTipoYColor(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo[], Color colores[],int tamcol, Cliente clientes[],int tamcli);
void menuInfo();
void mostrarInformes(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo[], Color colores[],int tamcol, Cliente clientes[],int tamcli);
