#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombreC[20];
    char sexo;

}Cliente;


#endif // CLIENTE_H_INCLUDED
int cargarDescripcionNombreDuenio(char nombreDuenio[], int idDuenio, Cliente clientes[], int tamcli);
