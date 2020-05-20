#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"
#include "cliente.h"
#include "color.h"
#include "tipos.h"
#include "trabajos.h"
#include "informes.h"

#define CANTHARDCODE 4

#define TAMMASCOTA 10
#define TAMTIPO 5
#define TAMCOL 5
#define TAMSERV 4
#define TAMTRAB 4
#define TAMCLI 4


int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 100;
    int proximoIdTrab = 1000;

    Mascota mascotas[TAMMASCOTA];

     Tipo tipos[TAMTIPO] =
    {
        {1000, "ave"},
        {1002, "perro"},
        {1003, "gato"},
        {1004, "roedor"},
        {1005, "pez"}
    };
      Servicio servicios [TAMSERV] =
    {
        {20000, "corte",250},
        {20001, "Desparasitado",300},
        {20002, "castrado",400},
        {20003, "limpieza",150},
    };

     Trabajo trabajos [TAMTRAB]=
     {{20000, "corte",250},{20001, "Desparasitado",300},{20002, "castrado",400},{20003, "limpieza",150}};*/


    Color colores[TAMCOL] =
    {{5000, "negro"},{5001, "blanco"},{5002, "gris"},{5003, "rojo"},{5004, "azul"}};

     Tipo tipos[TAMTIPO] =
    {
        {1000, "ave", 'f'},
        {1002, "perro"},
        {1003, "gato"},
        {1004, "roedor"},
        {1005, "pez"}
    };
    Cliente clientes [TAMCLI];
    inicializarMascota(mascotas,TAMMASCOTA);
    harcodearMascota(mascotas, CANTHARDCODE);
    proximoId += CANTHARDCODE;

     do{
        switch(menuInicio())
        {
            case 1:
                if(altaMascota(proximoId,mascotas, TAMMASCOTA, tipos, TAMTIPO,colores,TAMCOL,clientes,TAMCLI) == 1)
                {
                    proximoId++;
                }
                break;
            case 2:
                modificarMascota(mascotas, TAMMASCOTA, tipos, TAMTIPO,colores,TAMCOL,clientes,TAMCLI);
                break;
            case 3:
                bajaMascota(mascotas, TAMMASCOTA, tipos, TAMTIPO,colores,TAMCOL,clientes,TAMCLI);
                break;
            case 4:
                printf("\n====Lista Ordenada por Tipo y Nombre===\n");
                listaMascotasPorTipoYNombre(mascotas, TAMMASCOTA, tipos, TAMTIPO,colores,TAMCOL);
                mostrarMascotas(mascotas, TAMMASCOTA, tipos, TAMTIPO,colores,TAMCOL,clientes,TAMCLI);
                break;
            case 5:
                system("cls");
                mostrarTiposMascotas(tipos,TAMTIPO);
                break;
            case 6:
                 system("cls");
                 mostrarColoresMascotas(colores,TAMCOL);
                break;
            case 7:
                 system("cls");
                 mostrarServicios(servicios, TAMSERV);
                 break;

            case 8:
                altaTrabajo(proximoIdTrab,trabajos,TAMTRAB, proximoId,mascotas, TAMMASCOTA,tipos, TAMTIPO, colores, TAMCOL, servicios, TAMSERV);
                break;

            case 9:
                 mostrarTrabajos(trabajos,TAMTRAB);
                 break;
            case 10:
                mostrarInformes( mascotas,  TAMASC,  tipos, TAMTIPO,  colores, TAMCOL,  clientes, TAMCLI)
                break;

            case 11:
                printf("Confirme salida: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
        }

        system("pause");

    }while(seguir == 's');



    return 0;
}

int menuInicio()
{
    int opcion;

    system("cls");
    printf("________________________________\n");
    printf(" ----- Gestion de Mascotas------\n");
    printf(" ===============================\n");
    printf("1 ===> ALTA DE MASCOTA\n");
    printf("2 ===> MODIICAR MASCOTA\n");
    printf("3 ===> BAJA DE MASCOTA\n");
    printf("4 ===> LISTAR MASCOTAS\n");
    printf("5 ===> LISTAR TIPOS MASCOTAS\n");
    printf("6 ===> LISTAR COLORES MASCOTAS\n");
    printf("7 ===> LISTAR SERVICIOS\n");
    printf("8 ===> ALTA DE TRABAJO\n");
    printf("9 ===> LISTAR TRABAJOS\n");
    printf("10 ===> INFORMES\n");
    printf("11 ===> SALIR <===\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
