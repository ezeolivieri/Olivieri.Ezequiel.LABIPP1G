#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "eAuto.h"
#include "eMarca.h"
#include "eColor.h"
#include "eCliente.h"
#include "Informes.h"
#include "eTrabajo.h"
#include "eServicio.h"

void mostrarAutosDeUnColor( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes, int idColor )
{
    int encontreUno = 0;

    if( autos != NULL && tam > 0 )
    {
        system("clear");

        printf("\n\n        *** LISTADO AUTOS DE UN COLOR ***            \n");
        printf(" IdAuto    Patente    Marca    Color     Modelo      Cliente\n");
        printf("---------------------------------------------------------------\n\n");

        for( int i=0; i<tam; i++ )
        {
            if( autos[i].isEmpty == 0 && autos[i].idColor == idColor )
            {
                encontreUno = 1;
                mostrarAuto( autos[i], marcas, tamM, colores, tamC, clientes, tamClientes);
            }
        }

        if( !encontreUno )
        {
            printf("\n\n No hay autos ingresados de ese color.\n");
        }

        printf("\n\n");

    }

}

void mostrarAutosDeUnaMarca( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes, int idMarca )
{
    int encontreUno = 0;
    char nombreMarca[15];
    obtenerDescripcionMarca(marcas, tamM, idMarca, nombreMarca);

    if( autos != NULL && tam > 0 )
    {

        printf("\n\n        *** LISTADO AUTOS DE MARCA: %10s ***            \n", nombreMarca);
        printf(" IdAuto    Patente    Marca    Color     Modelo      Cliente\n");
        printf("---------------------------------------------------------------\n\n");

        for( int i=0; i<tam; i++ )
        {
            if( autos[i].isEmpty == 0 && autos[i].idMarca == idMarca )
            {
                encontreUno = 1;
                mostrarAuto( autos[i], marcas, tamM, colores, tamC, clientes, tamClientes);
            }
        }

        if( !encontreUno )
        {
            printf("\n\n No hay autos ingresados de esa marca.\n");
        }

        printf("\n\n");

    }

}

void mostrarAutosMasViejos( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes )
{
    int masAntiguo = modeloMasAntiguo(autos, tam);

    if( autos != NULL && tam > 0 )
    {

        printf("\n\n        *** EL O LOS AUTOS MAS VIEJOS ***            \n");
        printf(" IdAuto    Patente    Marca    Color     Modelo      Cliente\n");
        printf("---------------------------------------------------------------\n\n");

        for( int i=0; i<tam; i++ )
        {
            if( autos[i].isEmpty == 0 && autos[i].modelo == masAntiguo )
            {
                mostrarAuto( autos[i], marcas, tamM, colores, tamC, clientes, tamClientes);
            }
        }

        printf("\n\n");

    }

}

int modeloMasAntiguo( eAuto autos[], int tam )
{
    int modeloAntiguo;

    if( autos != NULL && tam > 0)
    {
        modeloAntiguo = autos[0].modelo;

        for( int i = 1; i < tam; i++ )
        {
            if( autos[i].isEmpty == 0 && autos[i].modelo < modeloAntiguo )
            {
                modeloAntiguo = autos[i].modelo;
            }
        }
    }

    return modeloAntiguo;
}

void mostrarAutosSeparadoPorMarcas( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes )
{

    system("clear");

    for( int i = 0; i < tamM; i++)
    {
        if( cantAutosDeMarca( autos, tam, marcas[i].id ) )
        {
            mostrarAutosDeUnaMarca(autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes, marcas[i].id);
        }
    }

}

int cantAutosDeMarca( eAuto autos[], int tam, int marcaId )
{

    int cantidad = 0;

    for( int i = 0; i < tam; i++ )
    {

        if( autos[i].idMarca == marcaId )
        {
            cantidad++;
            break;
        }

    }

    return cantidad;

}

void mostrarCantidadAutosDeUnColorYMarca( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes, int idColor, int idMarca )
{

    int cantidad = 0;

    char color[15];
    obtenerNombreColor(colores, tamC, idColor, color);
    char marca[15];
    obtenerDescripcionMarca(marcas, tamM, idMarca, marca);


    for( int i = 0; i < tam; i++ )
    {

        if( autos[i].idColor == idColor && autos[i].idMarca == idMarca )
        {
            cantidad++;
            break;
        }

    }

    if( cantidad > 0 )
    {
        printf("\n\n LA CANTIDAD DE AUTOS DE %s, COLOR %s: %d\n\n", marca, color, cantidad);
    }
    else
    {
        printf("\n\n NO SE ENCONTRO NINGUN AUTO DE %s, COLOR %s.\n\n", marca, color);
    }

}

void mostrarMarcasMasElegidas( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes )
{
    int cantidadDeLaMarcaMasElegida = cantAutosConMarcaMasElegida(autos, tam, marcas, tamM);
    int cantidadComparar;

    if( marcas != NULL && tamM > 0 )
    {
        printf("\n\n        *** LA O LAS MARCAS MAS ELEGIDAS ***            \n");
        printf("         ------------------------------------------\n");
        printf("                 Id        Descripcion\n\n");


        for( int i=0; i<tamM; i++ )
        {
            cantidadComparar = cantAutosDeMarca(autos, tam, marcas[i].id);

            if( cantidadComparar == cantidadDeLaMarcaMasElegida )
            {
                mostrarMarca(marcas[i]);
            }
        }

        printf("\n\n");
    }
}

int cantAutosConMarcaMasElegida( eAuto autos[], int tam, eMarca marcas[], int tamM )
{
    int cantidad = cantAutosDeMarca(autos, tam, autos[0].idMarca);
    int cantComparar;

    for( int i = 1; i < tam; i++ )
    {
        cantComparar = cantAutosDeMarca(autos, tam, autos[i].idMarca);

        if( cantComparar > cantidad )
        {
            cantidad = cantComparar;
        }
    }

    return cantidad;
}

void mostrarTrabajosHechosAUnAuto( eTrabajo trabajos[], int tam, eAuto autos[], int tamA, eServicio servicios[], int tamS, int idAuto )
{

    int indiceAuto;
    int encontreUno = 0;

    if( trabajos != NULL && tam > 0)
    {

        printf("\n\n        *** TRABAJOS REALIZADOS A UN AUTO ***            \n");
        printf("         IdTrabajo    Patente    Servicio    Fecha\n");
        printf("       -----------------------------------------------\n\n");

        indiceAuto = buscarAuto(autos, tamA, idAuto);

        for(int i=0; i<tam; i++)
        {
            if( trabajos[i].isEmpty == 0 &&  strcmp(trabajos[i].patente, autos[indiceAuto].patente) == 0 )
            {
                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
                encontreUno = 1;
            }
        }

        if( !encontreUno )
        {
            printf("    No hay trabajos en la lista");
        }

        printf("\n\n");

    }

}

void sumaDeImportesHechosAUnAuto( eTrabajo trabajos[], int tamTs, eServicio servicios[], int tamS, eAuto autos[], int tam, int idAuto )
{

    float resultado = 0;
    int encontreUno = 0;
    int indiceAuto;
    int indiceServicio;

    for( int i = 0; i < tamTs; i++)
    {

        indiceAuto = buscarAuto(autos, tam, idAuto);

        if( strcmp(trabajos[i].patente, autos[indiceAuto].patente) == 0 )
        {
            encontreUno = 1;

            indiceServicio = buscarServicio(servicios, tamS, trabajos[i].idServicio);

            resultado += servicios[indiceServicio].precio;

        }

    }

    if( encontreUno )
    {
        printf("\n\n LA SUMA DE LOS IMPORTES HECHOS AL AUTO INDICADO ES DE: %.2f\n\n", resultado);
    }
    else
    {
        printf("\n\n NO SE ENCONTRO NINGUN TRABAJO CON ESA PATENTE DE AUTO.\n\n");
    }

}

void mostrarAutosFechaDeUnServicio( eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int idServicio )
{
    int encontreUno = 0;
    char descMarca[20];
    char descColor[20];
    char descServicio[20];

    if( trabajos != NULL && tamTs > 0)
    {

        printf("\n\n        *** AUTOS Y FECHA DE SERVICIO SELECCIONADO ***            \n");
        printf("         Patente    Marca    Color     Modelo    Servicio    Fecha\n");
        printf("       --------------------------------------------------------------\n\n");

        for( int i=0; i<tamTs; i++ )
        {
            if(trabajos[i].isEmpty == 0 &&
               trabajos[i].idServicio == idServicio)
            {
                for( int j=0; i<tam; i++ )
                {
                    if( strcmp(autos[j].patente, trabajos[i].patente) == 0 )
                    {
                        encontreUno = 1;

                        obtenerDescripcionMarca(marcas, tamM, autos[j].idMarca, descMarca);
                        obtenerNombreColor(colores, tamC, autos[j].idColor, descColor);
                        obtenerDescripcionServicio(servicios, tamS, idServicio, descServicio);

                        printf("    %10s  %10s  %10s  %4d  %10s  %02d/%02d/%d\n",
                                autos[j].patente,
                                descMarca,
                                descColor,
                                autos[j].modelo,
                                descServicio,
                                trabajos[i].fecha.dia,
                                trabajos[i].fecha.mes,
                                trabajos[i].fecha.anio);
                    }
                }
            }
        }

        if( !encontreUno )
        {
            printf("    No hay ningun auto asociado a este servicio.");
        }

        printf("\n\n");

    }

}

void mostrarServiciosEnFecha( eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, eFecha fecha )
{
    int indiceServicio;
    int encontreUno = 0;

    if( trabajos != NULL && tamTs > 0 )
    {
        printf("\n\n        *** SERVICIOS DE LA FECHA SELECCIONADA ***            \n");
        printf("         ------------------------------------------------\n");
        printf("                 Id        Descripcion        Precio\n\n");


        for( int i=0; i<tamTs; i++)
        {

            if( esLaMismaFecha( trabajos[i].fecha, fecha ) )
            {
                encontreUno = 1;

                indiceServicio = buscarServicio( servicios, tamS, trabajos[i].idServicio );
                mostrarServicio( servicios[indiceServicio] );
            }

        }

        if( !encontreUno )
        {
            printf("\n\n No se encontro ningun servicio en esa fecha. \n\n");
        }
    }

}


