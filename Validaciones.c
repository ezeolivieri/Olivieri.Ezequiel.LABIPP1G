#include <string.h>
#include <ctype.h>

#include "eAuto.h"
#include "eCliente.h"
#include "eColor.h"
#include "eFecha.h"
#include "eMarca.h"
#include "eServicio.h"
#include "eTrabajo.h"


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

int tieneFormatoDePatente( char patente[] )
{
    int esValido = 0;

    if( patente != NULL )
    {

        // FORMATO NUEVO (2 LETRAS + 3 NUMEROS + 2 LETRAS)
        if( isalpha(patente[0]) && isalpha(patente[1]) &&
            isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) &&
            isalpha(patente[5]) && isalpha(patente[6])  )
        {
            esValido = 1;
        }

    }

    return esValido;
}

int validarIdAuto(eAuto autos[], int tam, int id)
{
    int esValido = 0;

    if( autos != NULL && tam > 0 && id >= 2500 )
    {
        for( int i=0; i<tam; i++ )
        {
            if( autos[i].id == id ){
                esValido=1;
                break;
            }
        }
    }

    return esValido;
}

int validarIdCliente(eCliente clientes[], int tam, int id)
{
    int esValido = 0;

    if( clientes != NULL && tam > 0 && id >= 1000 )
    {

        for( int i=0; i<tam; i++ )
        {
            if( clientes[i].id == id )
            {
                esValido = 1;
                break;
            }
        }

    }

    return esValido;
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

int validarFecha( eFecha fecha )
{
    int esValida = 0;

    if( fecha.anio > 1900 && fecha.anio <= 2021 )
    {

        if( fecha.mes >= 1 && fecha.mes <= 12)
        {

            switch( fecha.mes )
            {

                case 1:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

                case 2:
                    if( fecha.dia >= 1 && fecha.dia <= 29 )
                    {
                        esValida = 1;
                    }
                    break;

                case 3:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

                case 4:
                    if( fecha.dia >= 1 && fecha.dia <= 30 )
                    {
                        esValida = 1;
                    }
                    break;

                case 5:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

                case 6:
                    if( fecha.dia >= 1 && fecha.dia <= 30 )
                    {
                        esValida = 1;
                    }
                    break;

                case 7:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

                case 8:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

                case 9:
                    if( fecha.dia >= 1 && fecha.dia <= 30 )
                    {
                        esValida = 1;
                    }
                    break;

                case 10:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

                case 11:
                    if( fecha.dia >= 1 && fecha.dia <= 30 )
                    {
                        esValida = 1;
                    }
                    break;

                case 12:
                    if( fecha.dia >= 1 && fecha.dia <= 31 )
                    {
                        esValida = 1;
                    }
                    break;

            }

        }

    }

    return esValida;
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



