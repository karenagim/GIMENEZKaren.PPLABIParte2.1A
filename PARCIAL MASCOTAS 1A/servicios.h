#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int idServicio;
    char descripcion[20];
    float precio;

}Servicio;

#endif // SERVICIOS_H_INCLUDED

void mostrarServicios(Servicio servicios[], int tamserv);
int cargarDescripcionServicio(char descripcion[], int idserv, Servicio servicios[], int tamserv);
int buscarPrecioServPorId (int idABuscar, Servicio servicios[], int taserv);
