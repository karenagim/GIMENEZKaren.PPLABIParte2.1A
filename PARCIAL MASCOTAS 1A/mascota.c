#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DATAMASCOTA.h"
#include "VALIDACION.h"
#include "mascota.h"
#include "cliente.h"
#include "tipos.h"
#include "servicios.h"


void inicializarMascota(Mascota mascotas[],int tammascota)
{
     for(int i=0; i<tammascota; i++)
    {
        mascotas[i].activo=0;
    }
}
int buscarLibreMascota(Mascota mascotas[],int tammascota)
{
    int hayLibre= -1;
    for(int i=0; i<tammascota; i++)
    {
        if(mascotas[i].activo==0)
        {
             hayLibre=i;
             break;
        }

    }
    return hayLibre;
}
void harcodearMascota(Mascota mascotas[], int tamMascota)
{
    for(int i=0; i<tamMascota;i++)
    {
        mascotas[i].idMascota=idM[i];
        strcpy(mascotas[i].nombre,nombresM[i]);
        mascotas[i].idTipo=idTiposM[i];
        mascotas[i].idColor=idColores[i];
        mascotas[i].edad=edadM[i];
        mascotas[i].idDuenio=dueniosM[i];

        mascotas[i].activo=1;

    }
}

void mostrarMascota(Mascota mascota,Tipo tipos[],int tamTipo,Color colores[],int tamcol,Cliente clientes[],int tamcli)
{
     char nombreDuenio[21];
    char descripcionTipoM[21];
    char colorMascota[21];

    cargarDescripcionNombreDuenio(nombreDuenio, mascota.idDuenio,clientes,tamcli);
    cargarDescripcionTipo(descripcionTipoM,mascota.idTipo,tipos,tamTipo);
    cargarNombreColor(colorMascota,mascota.idColor,colores,tamcol);

    printf("%4d     %10s            %10s       %d     %10s      %d    %10s     %d \n\n", mascota.idMascota, mascota.nombre,nombreDuenio,mascota.idTipo, descripcionTipoM, mascota.idColor, colorMascota,mascota.edad);
}



void mostrarMascotas(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo,Color colores[],int tamcol,Cliente clientes[],int tamcli )
{
    int flag = 0;
    printf(" ________________________________________________________________________________\n");
    printf(" -------------------------- LISTADO DE MASCOTAS----------------------------------\n");
    printf(" ================================================================================\n");
    printf("  Id        Nombre      DUENIO     ID_TIPO         TIPO       ID_COLOR      COLOR      EDAD\n");
    for(int i=0; i<tamasc; i++)
    {
        if(mascotas[i].activo == 1)
        {
            mostrarMascota(mascotas[i],tipos,tamTipo,colores, tamcol, clientes,tamcli);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** NO HAY MASCOTAS QUE MOSTRAR***\n");
    }
}


int altaMascota(int proxId,Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol)
{
    int todoOk = 0;
    int indice = buscarLibreMascota(mascotas, tamasc);
    char auxNombre[20];
    Mascota auxMascota;

    system("cls");

    printf(" ________________________________________________________________________________\n\n");
    printf(" -------------------------- ALTA-MASCOTA----------------------------------\n\n");
    printf(" ================================================================================\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
            auxMascota.idMascota = proxId;

            //NOMBRE
            getString(auxNombre, 20, "Ingrese nombre mascota: ", "Error, nombre demasiado largo hasta 19 caracteres , reingrese nombre mascota: ");
            strcpy(auxMascota.nombre, auxNombre);
            //TIPO MASCOTA
            mostrarTiposMascotas(tipos, tamTipo);
            auxMascota.idTipo= getInt("Ingrese ID_TIPO mascota: ", "Error re-Ingrese un valor entre 1000 y 1004 ", 1000, 1004);

            //COLOR
            mostrarColoresMascotas(colores,tamcol);
            auxMascota.idColor= getInt("Ingrese ID_COLOR mascota: ", "Error re-Ingrese un valor entre 5000 y 5004 ", 5000, 5004);

            //EDAD
            auxMascota.edad=getInt("Ingrese EDAD mascota: ", "Error re-Ingrese un valor entre 0 y 50 ", 0, 50);

            system("cls");

            auxMascota.activo = 1;

            mascotas[indice] = auxMascota; //copio al mascotastor a la nueva mascota
            todoOk = 1;

            if(todoOk==1)
            {
                printf("\n Alta Exitosa \n\n");
            }

    }

    return todoOk;

}



int buscarMascota (int idABuscar, Mascota mascotas[], int tamasc)
{
    int indice = -1;
    for(int i=0; i<tamasc; i++)
    {
        if(mascotas[i].idMascota == idABuscar && mascotas[i].activo == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//(descripcionNombreMascNombre, trabajo.idMascota, mascotas, tamMasc);
int cargarDescripcionNombreMascota(char descripcion[], int idM, Mascota mascotas[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(mascotas[i].idMascota == idM)
        {
            strcpy(descripcion, mascotas[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}




//-----------------Modificar Auxs

void modificarMascotaEdad(Mascota mascotas[], int tamasc, Tipo tipos[], int tamTipos, Color colores[], int tamcol,Cliente clientes[],int tamcli)
{
    int indice;
    int idBuscado;
    char confima;
    int nuevaEdad;

    system("cls");

    printf("*====MODIFICAR EDAD===*\n\n");

    printf("Ingrese id de la mascota a actualizar la edad: ");
    scanf("%d", &idBuscado);

    indice = buscarMascota (idBuscado,mascotas,tamasc);

    if(indice == -1)
    {
        printf("No existe una mascota con el ID ingresado\n\n");
    }
    else
    {
        mostrarMascota(mascotas[indice], tipos, tamTipos, colores, tamcol,clientes, tamcli);

        nuevaEdad = getInt("Ingrese edad nueva: ", "Error, ingrese una edad valida: ", 0, 50);

        printf("Confirma la edad nueva? antes: %d ==> ahora: %d s/n: ",nuevaEdad,mascotas[indice].edad);
        fflush(stdin);
        scanf("%c", &confima);

        if(confima == 's')
        {
            mascotas[indice].edad = nuevaEdad;
            printf("Se ha actualizado la edad  con exito\n\n");
        }
        else
        {
            printf("Se ha cancelaado la operacion\n\n");
        }
    }
}
void modificarMascotaTipo(Mascota mascotas[], int tamasc, Tipo tipos[], int tamTipos, Color colores[], int tamcol)
{
    int indice;
    int idBuscado;
    char confima;
    int nuevoTipo;

    system("cls");

    printf("*====MODIFICAR TIPO MASCOTA===*\n\n");

    printf("Ingrese id de la mascota a actualizar el TIPO\n");

    indice = buscarMascota (idBuscado,mascotas,tamasc);

    if(indice == -1)
    {
        printf("No existe una mascota con el ID ingresado\n\n");
    }
    else
    {

        nuevoTipo = getInt("Ingrese nuevo tipo: ", "Error, ingrese una tipo valida: ", 1000, 1004);

        printf("Confirma el nuevo tipo? antes: %d ==> ahora: %d s/n: ",nuevoTipo,mascotas[indice].idTipo);
        fflush(stdin);
        scanf("%c", &confima);

        if(confima == 's')
        {
            mascotas[indice].idTipo = nuevoTipo;
            printf("Se ha actualizado  el tipo  con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("_____________________________________\n");
    printf(" --------- LISTADO DE MASCOTAS-------\n");
    printf(" ====================================\n");
    printf("1 ===> Modificar TIPO\n");
    printf("2 ===> Modificar NOMBRE\n");
    printf("3 ===> SALIR <===\n");
    printf("3-Volver al menu principal\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void modificarMascota(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol,Cliente clientes[],int tamcli)
{
    int idMascota;
    int indice;
    char confirma;
    char seguir='s';


    system("cls");
    printf("***** Modificar Mascota *****\n\n");

    idMascota= getInt("Ingrese ID_mascota: ", "Error re-Ingrese un valor entre 1 y 999 ", 1, 999);

    indice = buscarMascota (idMascota,mascotas,tamasc);

    if(indice == -1)
    {
        printf("No existe una mascota con  Id: %d\n", idMascota);
    }
    else
    {
        mostrarMascota(mascotas[indice],tipos,tamTipo,colores, tamcol,clientes, tamcli);

        //SUBMENU---------------------------------------------------
        do{
            switch( menuModificacion())
            {
                    case 1 :
                            modificarMascotaTipo(mascotas,tamasc, tipos,  tamTipo,  colores,tamcol);
                            break;

                    case 2:
                            modificarMascotaEdad(mascotas,tamasc, tipos,  tamTipo,  colores,tamcol,clientes,tamcli);
                            break;

                    case 3:
                            printf("\nDesea salir?: s/n  \n");
                            fflush(stdin);
                            scanf("%c",&confirma);
                            if(confirma== 's')
                            {
                                seguir= 'n';
                            }
                    default:
                            system("cls");
                            printf("Ingrese una opcion valida\n");
                            system("pause");
                            fflush(stdin);
                            break;
            }

        }while(seguir == 's');
    }

}

void bajaMascota(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol,Cliente clientes[],int tamcli)
{
    int idMascota;
    int indice;
    char confirma;

   // system("cls");
    printf("=====Baja Mascota=====\n\n");

    idMascota= getInt("Ingrese ID mascota: ", "Error re-Ingrese un valor valido ",1 , 999);

    indice = buscarMascota (idMascota,mascotas,tamasc);

    if(indice == -1)
    {
        printf("No hay registro de una mascota con el Id: %d\n", idMascota);
    }
    else
    {
        mostrarMascota(mascotas[indice], tipos,tamTipo,colores,tamcol,clientes, tamcli);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            mascotas[indice].activo = 0;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

void listaMascotasPorTipoYNombre(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol)
{
    Mascota auxMascota;
    for (int i=0; i<tamasc-1; i++)
    {
        for (int j=i+1; j<tamasc; j++)
        {
            if(mascotas[i].idTipo < mascotas[j].idTipo)
            {
                auxMascota = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = auxMascota;
            }
            else if(mascotas[i].idTipo == mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0)
            {
                auxMascota = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = auxMascota;
            }

        }
     }
}

