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

int mostrarServicios(eServicio servicios[], int tam)
{
    int error = -1;

    if( servicios != NULL && tam > 0 )
    {
        printf("\n\n             *** LISTADO SERVICIOS ***          \n");
        printf("         ------------------------------------------------\n");
        printf("                 Id        Descripcion        Precio\n\n");

        for(int i=0; i<tam; i++)
        {
            mostrarServicio(servicios[i]);
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}

void mostrarServicio(eServicio servicio)
{
    printf("                 %d      %s      %6.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}



int obtenerDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[])
{
    int error = 1;

    if( servicios != NULL && tam > 0 && id >= 1000 && descripcion != NULL )
    {
        for (int i = 0; i<tam ; i++)
        {
            if( servicios[i].id == id )
            {
                strcpy( descripcion, servicios[i].descripcion );
                error = 0;
                break;
            }
        }
    }

    return error;

}


int validarIdServicio( eServicio servicios[], int tam, int id )
{
    int esValido = 0;

    if( servicios != NULL && tam > 0 && id >= 20000 ){

        for( int i=0; i<tam; i++ )
        {
            if( servicios[i].id == id ){
                esValido = 1;
                break;
            }
        }
    }

    return esValido;
}
