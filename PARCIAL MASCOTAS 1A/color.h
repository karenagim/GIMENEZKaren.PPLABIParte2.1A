#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int idColor;
    char nombreColor[20];

}Color;

int cargarNombreColor(char nombre[], int idCol, Color colores[], int tamcol);
void mostrarColoresMascotas(Color colores[], int tamcol);
void mostrarColoresMascotas(Color colores[], int tamcol);

#endif // COLOR_H_INCLUDED
