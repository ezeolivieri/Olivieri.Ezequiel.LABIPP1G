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

void mostrarColor(eColor color)
{
    printf("                 %d      %s\n", color.id, color.nombreColor);
}

int mostrarColores(eColor colores[], int tam)
{
    int error = -1;

    if( colores != NULL && tam > 0 )
    {
        printf("\n\n             *** LISTADO COLORES ***            \n");
        printf("        -------------------------------------------\n");
        printf("                 Id            Nombre\n\n");

        for( int i=0; i<tam; i++ )
        {
            mostrarColor(colores[i]);
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}

int validarIdColor(eColor colores[], int tam, int id)
{
    int esValido = 0;

    if( colores != NULL && tam > 0 && id >= 5000 )
    {
        for( int i=0; i<tam; i++ )
        {
            if( colores[i].id == id ){
                esValido=1;
                break;
            }
        }
    }

    return esValido;
}




int obtenerNombreColor(eColor colores[], int tam, int id, char nombreColor[])
{
    int error = 1;

    if( colores != NULL && tam > 0 && id >= 1000 && nombreColor != NULL )
    {
        for (int i = 0; i<tam ; i++)
        {
            if( colores[i].id == id )
            {
                strcpy( nombreColor, colores[i].nombreColor );
                error = 0;
                break;
            }
        }
    }

    return error;

}
