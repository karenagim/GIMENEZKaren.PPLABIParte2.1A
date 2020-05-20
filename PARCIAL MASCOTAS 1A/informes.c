#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascota.h"
#include "color.h"
#include "tipos.h"

void informarlistadeMascotasPorColor(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
{
	int idColorAMostrar;
	int flag = 0;

	system("cls");
	printf("***** Informe lista mascotas por COLOR *****\n\n");

	mostrarColoresMascotas(colores,tamcol);

	idColorAMostrar=getInt("Ingrese el id del color a listar:","ERROR, ID INCORRECTO, REINGRESE",5000,5004 );

	printf("  Id        Nombre      DUENIO     ID_TIPO         TIPO       ID_COLOR      COLOR      EDAD\n");
	for(int i = 0; i < tamasc ; i++)
	{
		if(mascotas[i].activo == 1 && mascotas[i].idColor == idColorAMostrar)
		{
		  mostrarMascota(mascotas[i],tamasc,tipos,tamtipo,colores,tamcol,clientes,tamcli);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("No hay mascotas con ese color\n\n");
	}
}

// Mostrar mascotas de un tipo seleccionado.

void informarlistadeMascotasPorTipo(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
{
	int idTipoAMostrar;
	int flag = 0;

	system("cls");
	printf("***** Informe lista mascotas por TIPOS *****\n\n");

	mostrarTiposMascotas(tipos,tamtipo);

	idTipoAMostrar=getInt("Ingrese el id del tipo a listar:","ERROR, ID_TIPO INCORRECTO, REINGRESE",1000,1005 );

	printf("  Id        Nombre      DUENIO     ID_TIPO         TIPO       ID_COLOR      COLOR      EDAD\n");
	for(int i = 0; i < tamasc ; i++)
	{
		if(mascotas[i].activo == 1 && mascotas[i].idTipo ==  idTipoAMostrar)
		{
			mostrarMascota(mascotas[i],tamasc,tipos,tamtipo,colores,tamcol,clientes,tamcli);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("NO HAY MASCOTAS CON ESE TIPO\n\n");
	}
}

//3-	Informar la o las mascotas de menor edad.
void informarlistadeMascotasPorMenorEdad(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
{
	Mascota auxMascota;
	int idTipoAMostrar;



	system("cls");
	printf("***** Informe MASCOTAS POR MENOR EDAD*****\n\n");

	printf("  Id        Nombre      DUENIO     ID_TIPO         TIPO       ID_COLOR      COLOR      EDAD\n");

    for (int i=0; i<tamasc-1; i++)
    {
        for (int j=i+1; j<tamasc; j++)
        {
            if(mascotas[i].activo == 1 && mascotas[i].idTipo ==  idTipoAMostrar)
            {
                if(mascotas[i].edad > mascotas[j].edad)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if(mascotas[i].idMascota == mascotas[j].idMascota && strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
     }

}


//4-	Listar de las mascotas separadas por tipo.
void informarMascotasPorTipo(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
{
   int flag=0;

    system("cls");
    printf("=====> INFORME MASCOTAS POR TIPO\n\n");

    for(int t=0; t<tamtipo; t++)
    {

        //printf("TIPOS: %s\n", tipos[t].descripcion);
       // printf(" ---------\n\n");

        //recorro las mascotas del tipo "t"
        for(int m=0; m<tammasc; m++)
        {
            if(mascotas[m].activo == 1 && mascotas[m].idTipo == tipos[t].idTipo)
            {
                mostrarMascotas(mascotas[m],tamasc,tipos,tamtipo,colores,tamcol,clientes,tamcli);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\n  NO HAY MASCOTAS CON ESE TIPO\n");
        }
        printf("\n--------------------------------------------------------------\n");
    }

}
/*


5-	Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.*/

void informarMascotasPorTipoYColor(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
{
   int flag;
   int idColorElegido;
   int idTipoElegido;
   int cantColTipElegido=0;

    system("cls");
    printf("=====> INFORME MASCOTAS POR TIPO Y COLOR\n\n");

    idColorElegido=getInt("Ingrese ID_COLOR mascota: ", "Error re-Ingrese un valor entre 5000 y 5004 ", 5000, 5004);
    idTipoElegido= getInt("Ingrese ID_TIPO mascota: ", "Error re-Ingrese un valor entre 1000 y 1004 ", 1000, 1004);

    //printf("TIPO: %s , COLOR\n", tipos.descripcion,colores[]);

    for(int t=0; t<tamtipo; t++)
    {
        flag = 0;
        if(tipos[t].idTipo == idTipoElegido)
        {
            for(int m=0; m<tammasc; m++)
            {
                if(mascotas[m].activo == 1 && mascotas[m].idColor == mascotas[m].idColorElegido)
                {
                    mostrarMascotas(mascotas,tamasc,tipos,tamtipo,colores,tamcol,clientes,tamcli);
                    flag = 1;
                    antColTipElegido++;
                }
            }
        }
        printf(" ---------\n\n");
        if(flag == 0)
        {
            printf("\n  NO HAY MASCOTAS CON ESE TIPO Y COLOR\n");
        }
        printf("\n--------------------------------------------------------------\n");
    }

}

void menuInfo()
{
    int opcion;
    system("cls");
    printf("________________________________\n");
    printf(" ----- MENU INFORMES------\n");
    printf(" ===============================\n");
    printf("1 ===> MOSTRAR MASCOTAS POR COLOR\n");
    printf("2 ===> MOSTRAR MASCOTAS POR TIPO SELECCIONADO\n");
    printf("3 ===> MOSTRAR LA/S MASCOTAS MAS JOVENES\n");
    printf("4 ===> MASCOTAS SEPARADAS POR TIPOS\n");
    printf("5 ===> CONTAR MASCOTAS POR COLOR Y TIPO\n");
    //printf("6 ===> MAXIMA CANT MASCOTAS POR COLOR\n");

    printf("6 ===> SALIR <===\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
}
void mostrarInformes(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
{
    char confirma='s';
    char seguir='s';


    switch(menuInfo())
    {
        case 1:
             informarlistadeMascotasPorColor(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli)
             break;
        case 2:
             listaMascotasPorTipoYNombre(Mascota mascotas[],int tamasc,Tipo tipos[],int tamTipo ,Color colores[],int tamcol,Cliente clientes[],int tamcli);
            break;
            case 3:
                informarlistadeMascotasPorMenorEdad(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli);
                break;
            case 4:
                informarMascotasPorTipo(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli);
                 break;
            case 5:
                informarMascotasPorTipoYColor(Mascota mascotas[], int tamasc, Tipo tipos[],int tamtipo, Color colores[],int tamcol, Cliente clientes[],int tamcli);
                break;


            case 6:
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

}

