#include <stdio.h>
#include <string.h>

#include "eCliente.h"

int obtenerNombreCliente(eCliente clientes[], int tam, int id, char nombreCliente[])
{
    int error = 1;

    if( clientes != NULL && tam > 0 && id >= 1000 && nombreCliente != NULL )
    {
        for ( int i = 0; i < tam; i++ )
        {
            if( clientes[i].id == id )
            {
                strcpy( nombreCliente, clientes[i].nombre );
                error = 0;
                break;
            }
        }
    }

    return error;
}

void mostrarCliente(eCliente cliente)
{
    printf("                 %d      %s       %c\n", cliente.id, cliente.nombre, cliente.sexo);
}

int mostrarClientes(eCliente clientes[], int tam)
{
    int error = -1;

    if( clientes != NULL && tam > 0 )
    {
        printf("\n\n             *** LISTADO CLIENTES ***            \n");
        printf("        -------------------------------------------\n");
        printf("                 Id            Nombre     Sexo\n\n");

        for( int i=0; i < tam; i++ )
        {
            mostrarCliente(clientes[i]);
        }

        printf("\n\n");
        error = 0;
    }

    return error;
}
