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

void mostrarMarca(eMarca marca)
{
    printf("                 %d      %s\n", marca.id, marca.descripcion);
}

int mostrarMarcas(eMarca marcas[], int tam)
{
    int error = -1;

    if( marcas != NULL && tam > 0 )
    {
        printf("\n\n             *** LISTADO MARCAS ***          \n");
        printf("         ------------------------------------------\n");
        printf("                 Id        Descripcion\n\n");

        for(int i=0; i<tam; i++)
        {
            mostrarMarca(marcas[i]);
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}

int validarIdMarca(eMarca marcas[], int tam, int id)
{
    int esValido = 0;

    if( marcas != NULL && tam > 0 && id >= 1000 )
    {
        for( int i=0; i<tam; i++ )
        {
            if( marcas[i].id == id ){
                esValido=1;
                break;
            }
        }
    }

    return esValido;
}

int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[])
{
    int error = 1;

    if( marcas != NULL && tam > 0 && id >= 1000 && descripcion != NULL )
    {
        for (int i = 0; i<tam ; i++)
        {
            if( marcas[i].id == id )
            {
                strcpy( descripcion, marcas[i].descripcion );
                error = 0;
                break;
            }
        }
    }

    return error;

}
