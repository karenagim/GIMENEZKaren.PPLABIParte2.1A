#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"
#include "tipos.h"
#include "servicios.h"
#include "trabajos.h"

#include "VALIDACION.h"



/*Se dará de alta cada ocurrencia de trabajo
pidiéndole al usuario que elija una mascota y un Servicio

*/
void inicializarTrabajos(Trabajo trabajos[], int tamTrab)
{
    for(int i=0; i<tamTrab; i++)
    {
        trabajos[i].ocupado = 0;
    }
}
int buscarLibreTrabajo(Trabajo trabajos[], int tamTrab)
{
    int indice = -1;
    for(int i=0; i<tamTrab; i++)
    {
        if(trabajos[i].ocupado==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
//------



void mostrarTrabajo(Trabajo trabajo, int tamTrab, Mascota mascotas[], int tamMasc, Servicio servicios[], int tamServ)
{
    char descripcionS[25];
    char descripcionNombreMas[20];

    cargarDescripcionServicio(descripcionS, trabajo.idServicio, servicios, tamServ);
    cargarDescripcionNombreMascota(descripcionNombreMas, trabajo.idMascota, mascotas, tamMasc);


    printf("    %d            %d     %10s     %10s       %.2f        %d/%d/%d \n", trabajo.idTrabajo, trabajo.idMascota, descripcionNombreMas, descripcionS, buscarPrecioServPorId(trabajo.idServicio,servicios,tamServ), trabajo.fechaTrabajo.dia, trabajo.fechaTrabajo.mes, trabajo.fechaTrabajo.anio);
}

void mostrarTrabajos(Trabajo trabajos[], int tamtrab, Mascota mascotas[], int tamasc, Servicio servicios[], int tamserv)
{
    int flag = 0;
    system("cls");
    printf("***** Lista de Trabajos *****\n\n");
    printf("  Id Trabajo   |   Id Mascota   |  Nombre   |  Servicio   |  Precio   |    Fecha    \n\n");

    for(int i=0; i<tamtrab; i++)
    {
        if(trabajos[i].ocupado == 1)
        {
            mostrarTrabajo(trabajos[i], tamtrab, mascotas, tamasc, servicios, tamserv);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay trabajos que mostrar\n\n");
    }
}
//----------------------
int altaTrabajo(int proxIdTrab, Trabajo trabajos[], int tamTrab, int proxIdMasc, Mascota mascotas[], int tamasc, Tipo tipos[], int tamtipo,Color colores[], int tamcol, Servicio servicios[], int tamserv,Cliente clientes[],int tamcli)
{
    int isOk = 0;
    Trabajo nuevoTrabajo;
    int indice;

    system("cls");
    printf("________________________________________________________\n\n");
    printf(" -------------------------- ALTA-TRABAJO----------------\n\n");
    printf(" =====================================================\n\n");

    indice = buscarLibreTrabajo(trabajos, tamTrab);

    if(indice == -1 )
    {
        printf("SISTEMA COMPLETO, NO SE PUEDEN ACEPTAR MAS TRABAJOS");
    }
    else
    {
        mostrarMascotas(mascotas, tamasc, tipos, tamtipo, colores, tamcol,clientes,tamcli);
        //id mascota
        nuevoTrabajo.idMascota = getInt("Ingrese id mascota: ", "Error, ingrese un id de mascota valido: ", 100, proxIdMasc-1);
        mostrarServicios(servicios, tamserv);
        //servicio
        nuevoTrabajo.idServicio = getInt("Ingrese id de servicio: ", "Error, ingrese un id de servicio valido: ", 20000, 20003);
        //fecha
        printf("***Ingrese fecha***\n\n");
       printf("Ingrese fecha dd/mm/aaaa: ");
        fflush(stdin);

        nuevoTrabajo.fechaTrabajo.dia = getInt("Ingrese dia: ", "Error, ingrese un dia valido: ", 1, 31);
        nuevoTrabajo.fechaTrabajo.mes = getInt("Ingrese mes: ", "Error, ingrese un mes valido: ", 1, 12);
        nuevoTrabajo.fechaTrabajo.anio = getInt("Ingrese anio: ", "Error, ingrese un anio valido: ", 1999, 2020);
//



        nuevoTrabajo.idTrabajo = proxIdTrab;
        nuevoTrabajo.ocupado = 1;

        trabajos[indice] = nuevoTrabajo;

        isOk = 1;

        printf("Alta trabajo exitosa!\n\n");
    }
    return isOk;
}
