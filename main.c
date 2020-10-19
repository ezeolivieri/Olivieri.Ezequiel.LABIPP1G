#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#include "eAuto.h"
#include "eMarca.h"
#include "eTrabajo.h"
#include "eColor.h"
#include "eFecha.h"
#include "eServicio.h"

#define TRUE     1
#define FALSE    0
#define CANTIDAD 10
#define CANT_M   5
#define CANT_T   5
#define CANT_C   5
#define CANT_S   4

/***********************
        PROTOTIPOS
 ***********************/

/** \brief Despliegue de menu principal
 *
 * \return char Opcion ingresada por el usuario
 *
 */
char menu();

/** \brief Despliegue de un subMenu con las listas disponibles
 *
 * \return char Opcion ingresada por el usuario
 *
 */
char subMenuListas();

/** \brief Dada una opcion muestra una determinada información en forma de tabla
 *
 * \param opcion char
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param servicios[] eServicio
 * \param tamS int
 * \param trabajos[] eTrabajo
 * \param tamTs int
 * \return void
 *
 */
void mostrarListaSegunOpcion( char opcion, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs );

/** \brief Muestra por pantalla una confirmacion de salida y retorna la respuesta
 *
 * \return char
 *
 */
char confirmacionSalida();







int main()
{
    int continuar = TRUE;
    int respuesta;
    int ingresados = 0;
    int proxIdAuto = 2500;
    int proxIdTrabajo = 12500;
    char opcion;
    eAuto autos[CANTIDAD];
    eTrabajo trabajos[CANT_T];


    /**********************
          DATOS PREVIOS
     **********************/
    eMarca marcas[CANT_M]=
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };
    eColor colores[CANT_C]=
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };
    eServicio servicios[CANT_S]=
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };


    if( inicializarAutos(autos, CANTIDAD) == 0 )
    {
        printf("Autos inicializados con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar autos\n\n");
    }

    if( inicializarTrabajos(trabajos, CANT_T) == 0 )
    {
        printf("Trabajos inicializados con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar Trabajos\n\n");
    }

    // pauso la ejecución del programa
    system("read -p 'Press Enter to continue...' var");

    do
    {

        switch( menu() )
        {
            // ALTA AUTO
            case 'a':
                if( altaAuto(autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, proxIdAuto) == 0 )
                {
                    proxIdAuto++;
                    ingresados++;
                    printf("\n\nALTA EXITOSA!\n");
                }
                else
                {
                    printf("Problema para realizar el alta.");
                }
                break;

            // MODIFICAR AUTO
            case 'b':
                if( ingresados > 0 )
                {
                    respuesta = modificarAuto(autos, CANTIDAD, marcas, CANT_M, colores, CANT_C);

                    if( respuesta == 0)
                    {
                        printf("\n\nModificacion exitosa\n");
                    }
                    else if(respuesta == 2)
                    {
                        printf("\n\nLa modificacion ha sido cancelada por usuario\n");
                    }
                    else
                    {
                        printf("\n\nSe ha producido un error en la modificacion\n");
                    }
                }
                break;

            // BAJA AUTO
            case 'c':
                if( ingresados > 0 )
                {
                    respuesta = bajaAuto(autos, CANTIDAD, marcas, CANT_M, colores, CANT_C);

                    if( respuesta == 0)
                    {
                        ingresados--;
                        printf("Baja exitosa\n");
                    }
                    else if(respuesta == 2)
                    {
                        printf("Baja cancelada por usuario\n");
                    }
                    else
                    {
                        printf("Se ha producido un error en la baja\n");
                    }
                }

                break;

            // LISTAS
            case 'd':
                opcion = subMenuListas();
                if( opcion == 'f' )
                {
                    printf("\n\n     Volviendo al menú principal... \n\n");
                }
                else
                {
                    mostrarListaSegunOpcion(opcion, autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, servicios, CANT_S, trabajos, CANT_T);
                }
                break;

            // ALTA TRABAJO
            case 'e':
                if( altaTrabajo(trabajos, CANT_T, autos, CANTIDAD, servicios, CANT_S, marcas, CANT_M, colores, CANT_C, proxIdTrabajo) == 0 )
                {
                    proxIdTrabajo++;
                    printf("\n\nALTA EXITOSA!\n");
                }
                else
                {
                    printf("Problema para realizar el alta.");
                }
                break;

            // SALIR
            case 'f':
                if ( confirmacionSalida() == 's' )
                    continuar = FALSE;
                break;

            // CUALQUIER OTRA OPCION => ERROR
            default:
                printf("\n\nOpcion invalida!!!\n");
                break;
        }

        // pauso la ejecución del programa
        system("read -p 'Press Enter to continue...' var");

    }
    while( continuar );



    return 0;
}



/*******************************
            FUNCIONES
 *******************************/

char menu()
{
    char opcion;
    system("clear");

    printf("\n\n\n             ~~~~~~   LAVADERO DE AUTOS   ~~~~~~\n\n");
    printf("             a) Alta\n");
    printf("             b) Modificacion\n");
    printf("             c) Baja\n");
    printf("             d) Listas\n");
    printf("             e) Alta de Trabajo\n");
    printf("             f) Salir\n\n");
    printf("             Ingrese opcion: ");
    __fpurge(stdin);
    opcion = tolower(getchar());

    return opcion;
}

char subMenuListas()
{
    char opcion;
    system("clear");

    printf("\n\n\n             ~~~~~~   MENU DE LISTAS   ~~~~~~\n\n");
    printf("             a) Autos\n");
    printf("             b) Marcas\n");
    printf("             c) Colores\n");
    printf("             d) Servicios\n");
    printf("             e) Trabajos\n");
    printf("             f) Volver\n\n");
    printf("             Ingrese opcion: ");
    __fpurge(stdin);
    opcion = tolower(getchar());

    return opcion;
}

void mostrarListaSegunOpcion( char opcion, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs )
{
    switch( opcion )
    {
        //AUTOS
        case 'a':
            ordenarAutosPorMarcaPatente( autos, tam );
            mostrarAutos( autos, tam, marcas, tamM, colores, tamC );
            break;
        //MARCAS
        case 'b':
            mostrarMarcas( marcas, tamM );
            break;
        //COLORES
        case 'c':
            mostrarColores( colores, tamC );
            break;
        //SERVICIOS
        case 'd':
            mostrarServicios( servicios, tamS );
            break;
        //TRABAJOS
        case 'e':
            mostrarTrabajos( trabajos, tamTs, autos, tam, servicios, tamS );
            break;
        //OPCION INVALIDA
        default:
            printf("\n\n       OPCION INVALIDA.\n\n");
            break;
    }


}

char confirmacionSalida()
{
    char confirm;

    printf("\n\nEstá seguro que desea salir?\n\n");
    __fpurge(stdin);
    scanf("%c", &confirm);
    confirm = tolower(confirm);

    return confirm;
}


