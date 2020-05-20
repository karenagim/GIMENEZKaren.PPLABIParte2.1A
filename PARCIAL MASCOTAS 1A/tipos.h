#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int idTipo;//comienza en 1000
    char descripcion[20];

}Tipo;


int cargarDescripcionTipo(char descripcion[], int idTipo, Tipo tipos[], int tamTipo);
void mostrarTiposMascotas(Tipo tipos[], int tamtipo);
//void listaTiposMascotas(Tipo tipos[], int tamtipo);

#endif // TIPOS_H_INCLUDED
