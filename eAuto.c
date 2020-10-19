#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#include "eAuto.h"
#include "eFecha.h"
#include "eMarca.h"
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

int inicializarAutos(eAuto autos[], int tam)
{
    int error = 1;

    if( autos!=NULL && tam > 0 )
    {
        for( int i=0; i<tam; i++ )
        {
            autos[i].isEmpty = 1;
        }
        error = 0;
    }

    return error;
}
int buscarAutoLibre(eAuto autos[], int tam)
{
    int indice = -1;

    for( int i = 0; i < tam; i++ )
    {
        if( autos[i].isEmpty )
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int idAuto)
{

    int error = 1;
    int indice;
    int auxIdMarca;
    int auxIdColor;
    float precioNote;
    eAuto nuevoAuto;

    if( autos!=NULL && tam > 0 && idAuto > 0 )
    {

        system("clear");
        printf("\n\n\n             ~~~~~~   ALTA DE AUTO   ~~~~~~\n\n");
        indice = buscarAutoLibre(autos, tam);

        if(indice == -1)
        {
            printf("             El sistema esta completo.\n");
        }
        else
        {
            nuevoAuto.id = idAuto;
            nuevoAuto.isEmpty = 0;

            printf("\n\n     INGRESE PATENTE: ");
            __fpurge(stdin);
            gets(nuevoAuto.patente);

            while( strlen( nuevoAuto.patente )!=7 )
            {
                system("clear");
                printf("\n\n   ERROR. REINGRESE PATENTE: ");
                __fpurge(stdin);
                gets(nuevoAuto.patente);
            }
            printf("\n\n");

            mostrarMarcas( marcas, tamM );
            printf("\n\n    INGRESE ID MARCA: ");
            scanf("%d", &auxIdMarca);
            while( validarIdMarca(marcas,tamM, auxIdMarca) == 0 )
            {
                printf("    ID INVALIDO.  \n");
                printf("REINGRESE ID MARCA: ");
                scanf("%d", &auxIdMarca);
            }

            nuevoAuto.idMarca = auxIdMarca;

            printf("\n\n");

            mostrarColores( colores, tamC );

            printf("\n\n    INGRESE ID COLOR: ");
            scanf("%d", &auxIdColor);

            while( validarIdColor( colores, tamC, auxIdColor ) == 0 )
            {
                printf("    ID INVALIDO. REINGRESE ID COLOR:  \n");
                scanf("%d", &auxIdColor);
            }

            nuevoAuto.idColor = auxIdColor;

            printf("\n\n    INGRESE MODELO (FECHA DE FABRICACION): ");
            scanf("%d", &nuevoAuto.modelo);

            while( nuevoAuto.modelo < 1950 || nuevoAuto.modelo>2020 )
            {
                printf("\n\n        ERROR. REINGRESE: ");
                scanf("%d", &nuevoAuto.modelo);
            }

            autos[indice] = nuevoAuto;
            error = 0;

        }

    }

    return error;

}
int buscarAuto(eAuto lista[], int tam, int idAuto)
{
    int indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if( lista[i].id == idAuto && lista[i].isEmpty == 0 )
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC )
{
    int error = -1;
    int flag = 0;

    if( autos != NULL && tam > 0 )
    {
        printf("\n\n        *** LISTADO AUTOS ***            \n");
        printf(" IdAuto    Patente    Marca    Color     Modelo\n");
        printf("-------------------------------------------------\n\n");

        for( int i=0; i<tam; i++ )
        {
            if( autos[i].isEmpty == 0 )
            {
                mostrarAuto( autos[i], marcas, tamM, colores, tamC);
                flag = 1;
            }
        }

        if( flag == 0 )
        {
            printf("\n\n    No hay autos en la lista");
        }
        printf("\n\n");

        error = 0;

    }

    return error;

}

int ordenarAutosPorMarcaPatente(eAuto list[], int tam)
{

    int error = 1;
    char auxMarcaI[25];
    char auxMarcaJ[25];

    if( list != NULL && tam > 0 )
    {

        error = 0;

        for( int i = 0; i < tam-1; i++ )
        {

            for( int j = i+1; j < tam; j++ )
            {

                if( strcmp( list[i].patente, list[j].patente) > 0 )
                {
                    autoSwap(&list[i], &list[j]);
                }
                else
                {
                    obtenerDescripcionMarca( list, tam, list[i].id, auxMarcaI );
                    obtenerDescripcionMarca( list, tam, list[j].id, auxMarcaJ );

                    if( strcmp(auxMarcaI, auxMarcaJ) > 0 )
                    {
                        autoSwap(&list[i], &list[j]);
                    }
                }

            }

        }

    }

    return error;

}

int autoSwap(eAuto* a, eAuto* b)
{
    int error = -1;

    if( a != NULL && b != NULL)
    {
        error = 0;
        eAuto aux;

        aux = *a;
        *a = *b;
        *b = aux;
    }

    return error;
}

void mostrarAuto(eAuto car, eMarca marcas[], int tamM, eColor colores[], int tamC)
{

    char descMarca[20];
    char descColor[20];

    if( (obtenerDescripcionMarca(marcas,tamM, car.idMarca, descMarca) == 0 ) &&
        (obtenerNombreColor(colores,tamC, car.idColor, descColor) == 0 ))
    {
        printf(" %5d  %10s  %10s  %10s  %4d\n",
                   car.id,
                   car.patente,
                   descMarca,
                   descColor,
                   car.modelo );
    }
    else
    {
        printf("Problema al obtener descripciones de marca y/o color\n\n");
    }

}
int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error = 1;
    int idAuto;
    int indice;
    int respuesta;
    int nuevoModelo = 0;
    int nuevoColor = 0;
    char auxDescColor[20];
    char confirma;


    if( autos != NULL && tam > 0 )
    {

        system("clear");
        printf("\n\n\n    *** MODIFICAR AUTO ***\n");
        ordenarAutosPorMarcaPatente( autos, tam );
        mostrarAutos(autos, tam, marcas, tamM, colores, tamC);
        printf("Ingrese el ID del Auto: ");
        scanf("%d", &idAuto);

        indice = buscarAuto(autos, tam, idAuto);

        if( indice == -1)
        {
            printf("\n\nNo existe un auto con ese id.\n");
        }
        else
        {

            mostrarAuto(autos[indice], marcas, tamM, colores, tamC);

            // PEDIR EL CAMPO A MODIFICAR
            // SE DEBE PODER MODIFICAR MODELO O COLOR
            printf("\n\n      INGRESE CAMPO A MODIFICAR\n");
            printf("     1 - MODELO\n     2 - COLOR\n");
            printf("\n     Respuesta: ");
            scanf("%d", &respuesta);

            while( respuesta != 1 && respuesta != 2 )
            {
                printf("\n     ERROR. REINGRESE: ");
                scanf("%d", &respuesta);
            }

            if( respuesta == 1 )
            {
                printf("\n      Ingrese el nuevo modelo: ");
                scanf("%d", &nuevoModelo);
                printf("\n   Nuevo modelo:  %4d  \n", nuevoModelo);
            }
            else
            {
                mostrarColores(colores, tamC);
                printf("\n      Ingrese el ID del color: ");
                scanf("%d", &nuevoColor);
                obtenerNombreColor(colores, tamC, nuevoColor, auxDescColor);
                printf("\n   Nuevo color:  %s  \n", auxDescColor);
            }

            printf("     Confirma modificacion?");
            __fpurge(stdin);
            scanf("%c", &confirma);

            if (confirma == 's')
            {

                // MODIFICAR MODELO O COLOR
                if( respuesta == 1 )
                {
                    autos[indice].modelo = nuevoModelo;
                }
                else
                {
                    autos[indice].idColor = nuevoColor;
                }
                error = 0;

            }
            else
            {
                error = 2;
            }

        }

    }

    return error;

}

int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error = 1;
    int idAuto;
    int indice;
    int confirma;

    if( autos != NULL && tam > 0 )
    {
        system("clear");
        printf("    *** BAJA DE AUTO ***\n");
        ordenarAutosPorMarcaPatente( autos, tam );
        mostrarAutos(autos, tam, marcas, tamM, colores, tamC);
        printf("Ingrese el ID del Auto: ");
        scanf("%d", &idAuto);

        indice = buscarAuto(autos, tam, idAuto);

        if( indice == -1)
        {
            printf("No existe un auto con ese ID.\n");
        }
        else
        {
            mostrarAuto(autos[indice], marcas, tamM, colores, tamC);
            printf("\n\nConfirma baja\n");
            printf("1 - SI\n2 - NO\n");
            printf("\nRespuesta: ");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                autos[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }

    return error;

}
int obtenerPatenteAuto(eAuto autos[], int tam, char patenteBuscar[], char patenteGuardar[])
{
    int error = 1;

    if( autos != NULL && tam > 0 && patenteBuscar != NULL && patenteGuardar != NULL )
    {
        for (int i = 0; i<tam ; i++)
        {
            if( strcmp(autos[i].patente, patenteBuscar) == 0 )
            {
                strcpy( patenteGuardar, autos[i].patente );
                error = 0;
                break;
            }
        }
    }

    return error;

}
int validarPatenteAuto(eAuto autos[], int tam, char patente[])
{
    int esValido = 0;

    if( autos != NULL && tam > 0 && patente != NULL ){
        for( int i=0; i<tam; i++ )
        {
            if( strcmp(autos[i].patente, patente) == 0 ){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}
