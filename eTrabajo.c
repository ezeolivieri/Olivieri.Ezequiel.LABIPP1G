#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#include "eFecha.h"
#include "eMarca.h"
#include "eAuto.h"
#include "eTrabajo.h"
#include "eServicio.h"
#include "eColor.h"

#define TRUE     1
#define FALSE    0
#define CANTIDAD 10
#define CANT_M   5
#define CANT_T   5
#define CANT_C   5
#define CANT_S   4

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int error = 1;

    if( trabajos!=NULL && tam > 0 )
    {
        for( int i=0; i<tam; i++ )
        {
            trabajos[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}

int buscarWorkLibre(eTrabajo works[], int tam)
{
    int indice = -1;

    for( int i = 0; i < tam; i++ )
    {
        if( works[i].isEmpty )
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int mostrarTrabajos(eTrabajo trabajos[], int tam, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    int error = 1;
    int flag = 0;

    if( trabajos != NULL && tam > 0)
    {
        //system("cls");
        printf(" IdTrabajo    Patente    Servicio    Fecha\n");
        printf("-----------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
                flag = 1;
            }
        }

        if( flag == 0 )
        {
            printf("    No hay trabajos en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;
}

void mostrarTrabajo(eTrabajo trabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS)
{
    char descServicio[25];
    char patenteAuto[9];

    if( (obtenerDescripcionServicio(servicios,tamS, trabajo.idServicio, descServicio) == 0) &&
        (obtenerPatenteAuto(autos, tamA, trabajo.patente, patenteAuto) == 0) )
    {
        printf(" %5d  %10s  %10s        %02d/%02d/%d\n",
               trabajo.id,
               patenteAuto,
               descServicio,
               trabajo.fecha.dia,
               trabajo.fecha.mes,
               trabajo.fecha.anio);
    }
    else
    {
        printf("Problema al obtener descripciones de servicio y/o modelo notebook\n\n");
    }
}
int altaTrabajo(eTrabajo works[], int tam, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, int idWork)
{

    int error = 1;
    int indice;
    int auxIdServ;
    eTrabajo nuevoWork;

    if( works != NULL && tam > 0 && idWork > 0 )
    {

        system("clear");
        printf("\n\n\n             ~~~~~~   ALTA DE TRABAJO   ~~~~~~\n\n");
        indice = buscarWorkLibre(works, tam);

        if(indice == -1)
        {
            printf("             El sistema esta completo.\n");
        }
        else
        {
            nuevoWork.id = idWork;
            nuevoWork.isEmpty = 0;

            ordenarAutosPorMarcaPatente( autos, tamA );
            mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);

            printf("\n\n             INGRESE PATENTE DE AUTO: ");
            __fpurge(stdin);
            gets(nuevoWork.patente);

            while( validarPatenteAuto(autos,tamA, nuevoWork.patente) == 0 )
            {
                printf("             PATENTE INVALIDA. REINGRESE PATENTE: ");
                __fpurge(stdin);
                gets(nuevoWork.patente);
            }

            mostrarServicios(servicios, tamS);

            printf("\n             INGRESE ID SERVICIO: ");
            scanf("%d", &auxIdServ);

            while( validarIdServicio(servicios,tamS, auxIdServ) == 0 )
            {
                printf("             ID INVALIDO. REINGRESE ID SERVICIO: ");
                scanf("%d", &auxIdServ);
            }

            nuevoWork.idServicio = auxIdServ;

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoWork.fecha.dia, &nuevoWork.fecha.mes, &nuevoWork.fecha.anio);

            works[indice] = nuevoWork;
            error = 0;
        }
    }

    return error;

}
