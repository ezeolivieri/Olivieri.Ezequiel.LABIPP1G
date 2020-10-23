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
#include "eCliente.h"
#include "Informes.h"
#include "Validaciones.h"

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
 * \param autosIngresados int
 * \return void
 *
 */
void mostrarListaSegunOpcion( char opcion, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, int autosIngresados, eCliente clientes[], int tamClientes );

/** \brief Despliegue de un subMenu con los informes disponibles
 *
 * \return char
 *
 */
char subMenuInformes();

/** \brief Dada una opcion muestra un determinado informe
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
 * \param autosIngresados int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return void
 *
 */
void mostrarInformeSegunOpcion( char opcion, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, int autosIngresados, eCliente clientes[], int tamClientes );

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
    int autosIngresados = 0;
    int proxIdAuto = 2500;
    int proxIdTrabajo = 12505;
    char opcion;
    eAuto autos[CANTIDAD];


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
    eCliente clientes[CANT_C]=
    {
        {1000, "Alberto", 'm'},
        {1001, "Valeria", 'f'},
        {1002, "Raul", 'm'},
        {1003, "Cinthia", 'f'},
        {1004, "Valerio", 'm'}
    };
    eTrabajo trabajos[CANT_T]=
    {
        {12500, "AP309LO", 20003, {9,12,2018}, 0},
        {12501, "LK900FD", 20001, {25,11,2016}, 0},
        {12502, "RW239CM", 20002, {1,10,2020}, 0},
        {12503, "CG095GC", 20001, {31,8,2020}, 0},
        {12504, "CG095GC", 20003, {31,8,2020}, 0}
    };


    if( inicializarAutos(autos, CANTIDAD) == 0 )
    {
        printf("Autos inicializados con exito!\n\n");
    }
    else
    {
        printf("Ha ocurrido un problema al inicializar autos\n\n");
    }

    // pauso la ejecución del programa
    system("read -p 'Press Enter to continue...' var");

    do
    {

        switch( menu() )
        {
            // ALTA AUTO
            case 'a':
                if( altaAuto(autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, proxIdAuto, clientes, CANT_C) == 0 )
                {
                    proxIdAuto++;
                    autosIngresados++;
                    printf("\n\nALTA EXITOSA!\n");
                }
                else
                {
                    printf("Problema para realizar el alta.");
                }
                break;

            // MODIFICAR AUTO
            case 'b':
                if( autosIngresados > 0 )
                {
                    respuesta = modificarAuto(autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, clientes, CANT_C);

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
                else
                {
                    printf("\n\nTodavia no hay ningun auto ingresado.\n");
                }
                break;

            // BAJA AUTO
            case 'c':
                if( autosIngresados > 0 )
                {
                    respuesta = bajaAuto(autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, clientes, CANT_C);

                    if( respuesta == 0)
                    {
                        autosIngresados--;
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
                else
                {
                    printf("\n\nTodavia no hay ningun auto ingresado.\n");
                }

                break;

            // LISTAS
            case 'd':
                opcion = subMenuListas();
                if( opcion == 'g' )
                {
                    printf("\n\n     Volviendo al menú principal... \n\n");
                }
                else
                {
                    mostrarListaSegunOpcion(opcion, autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, servicios, CANT_S, trabajos, CANT_T, autosIngresados, clientes, CANT_C);
                }
                break;

            // INFORMES
            case 'e':
                if( autosIngresados > 0 )
                {
                    opcion = subMenuInformes();

                    if( opcion == 'k' )
                    {
                        printf("\n\n     Volviendo al menú principal... \n\n");
                    }
                    else
                    {
                        mostrarInformeSegunOpcion(opcion, autos, CANTIDAD, marcas, CANT_M, colores, CANT_C, servicios, CANT_S, trabajos, CANT_T, autosIngresados, clientes, CANT_C);
                    }
                }
                else
                {
                    printf("\nPara ingresar a INFORMES debe haber al menos un auto ingresado.\n");
                }

                break;

            // ALTA TRABAJO
            case 'f':
                if( autosIngresados > 0 )
                {
                    if( altaTrabajo(trabajos, CANT_T, autos, CANTIDAD, servicios, CANT_S, marcas, CANT_M, colores, CANT_C, proxIdTrabajo, clientes, CANT_C) == 0 )
                    {
                        proxIdTrabajo++;
                        printf("\n\nALTA EXITOSA!\n");
                    }
                    else
                    {
                        printf("Problema para realizar el alta.");
                    }
                }
                else
                {
                    printf("\n\nTodavia no hay ningun auto ingresado.\n");
                }
                break;

            // SALIR
            case 'g':
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
    printf("             e) Informes\n");
    printf("             f) Alta de Trabajo\n");
    printf("             g) Salir\n\n");
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
    printf("             f) Clientes\n");
    printf("             g) Volver\n\n");
    printf("             Ingrese opcion: ");
    __fpurge(stdin);
    opcion = tolower(getchar());

    return opcion;
}

void mostrarListaSegunOpcion( char opcion, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, int autosIngresados, eCliente clientes[], int tamClientes )
{
    switch( opcion )
    {
        //AUTOS
        case 'a':
            if( autosIngresados > 0 )
            {
                ordenarAutosPorMarcaPatente( autos, tam, marcas, tamM);
                mostrarAutos( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes );
            }
            else
            {
                printf("\n\nTodavia no hay autos ingresados.\n");
            }
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
        //CLIENTES
        case 'f':
            mostrarClientes(clientes, tamClientes);
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

char subMenuInformes()
{
    char opcion;
    system("clear");

    printf("\n\n\n             ~~~~~~   MENU DE INFORMES   ~~~~~~\n\n");
    printf("             a) Mostrar autos de un color.\n");
    printf("             b) Mostrar autos de una marca.\n");
    printf("             c) Mostrar el o los autos más viejos.\n");
    printf("             d) Mostrar un listado de los autos separados por marca.\n");
    printf("             e) Contar cuantos autos hay dado un color y un marca.\n");
    printf("             f) Mostrar la o las marcas más elegidas por los clientes.\n");
    printf("             g) Mostrar todos los trabajos que se le hicieron a un auto.\n");
    printf("             h) Informar la suma de los importes que se le hicieron a un auto.\n");
    printf("             i) Mostrar los autos a los que se realizo un servicio y la fecha.\n");
    printf("             j) Mostrar todos los servicios realizados en una fecha.\n");
    printf("             k) Volver\n\n");
    printf("             Ingrese opcion: ");
    __fpurge(stdin);
    opcion = tolower(getchar());

    return opcion;
}

void mostrarInformeSegunOpcion( char opcion, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, int autosIngresados, eCliente clientes[], int tamClientes )
{
    int respuesta;
    int respuesta2;
    eFecha fecha;

    switch( opcion )
    {
        // MOSTRAR AUTOS DE UN COLOR
        case 'a':
            mostrarColores( colores, tamC );

            printf("\n\n    INGRESE ID COLOR: ");
            scanf("%d", &respuesta);

            while( validarIdColor( colores, tamC, respuesta ) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID COLOR:  \n");
                scanf("%d", &respuesta);
            }

            mostrarAutosDeUnColor( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes, respuesta );
            break;

        // MOSTRAR AUTOS DE UNA MARCA
        case 'b':
            mostrarMarcas( marcas, tamM );

            printf("\n\n    INGRESE ID MARCA: ");
            scanf("%d", &respuesta);

            while( validarIdMarca(marcas,tamM, respuesta) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID MARCA: \n");
                scanf("%d", &respuesta);
            }

            mostrarAutosDeUnaMarca( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes, respuesta );
            break;

        // MOSTRAR EL O LOS AUTOS MAS VIEJOS
        case 'c':
            mostrarAutosMasViejos( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes );
            break;

        // MOSTRAR LISTADO DE AUTOS SEPARADO POR MARCAS
        case 'd':
            mostrarAutosSeparadoPorMarcas( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes );
            break;

        // CONTAR CUANTOS AUTOS HAY DE UN COLOR Y MARCA
        case 'e':
            mostrarColores( colores, tamC );

            printf("\n\n    INGRESE ID COLOR: ");
            scanf("%d", &respuesta);

            while( validarIdColor( colores, tamC, respuesta ) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID COLOR:  \n");
                scanf("%d", &respuesta);
            }

            printf("\n\n");

            mostrarMarcas( marcas, tamM );

            printf("\n\n    INGRESE ID MARCA: ");
            scanf("%d", &respuesta2);

            while( validarIdMarca(marcas,tamM, respuesta2) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID MARCA: \n");
                scanf("%d", &respuesta2);
            }

            mostrarCantidadAutosDeUnColorYMarca( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes, respuesta, respuesta2 );
            break;

        // MOSTRAR LA O LAS MARCAS MAS ELEGIDAS POR LOS CLIENTES
        case 'f':
            mostrarMarcasMasElegidas( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes );
            break;

        // MOSTRAR TODOS LOS TRABAJOS HECHOS A UN AUTO
        case 'g':
            ordenarAutosPorMarcaPatente( autos, tam, marcas, tamM );
            mostrarAutos( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes );

            printf("\n\n             INGRESE ID DE AUTO: ");
            scanf("%d", &respuesta);

            while( validarIdAuto(autos,tam, respuesta) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID AUTO: \n");
                scanf("%d", &respuesta);
            }

            mostrarTrabajosHechosAUnAuto( trabajos, tamTs, autos, tam, servicios, tamS, respuesta);
            break;

        // SUMA DE IMPORTES QUE SE LE HICIERON A UN AUTO
        case 'h':
            ordenarAutosPorMarcaPatente( autos, tam, marcas, tamM );
            mostrarAutos( autos, tam, marcas, tamM, colores, tamC, clientes, tamClientes );

            printf("\n\n             INGRESE ID DE AUTO: ");
            scanf("%d", &respuesta);

            while( validarIdAuto(autos,tam, respuesta) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID AUTO: \n");
                scanf("%d", &respuesta);
            }

            sumaDeImportesHechosAUnAuto( trabajos, tamTs, servicios, tamS, autos, tam, respuesta);
            break;

        // MOSTRAR AUTOS Y FECHA DE UN SERVICIO
        case 'i':
            mostrarServicios(servicios, tamS);

            printf("\n\n             INGRESE ID DE SERVICIO: ");
            scanf("%d", &respuesta);

            while( validarIdServicio(servicios,tamS, respuesta) == 0 )
            {
                printf("\n    ID INVALIDO. REINGRESE ID SERVICIO: \n");
                scanf("%d", &respuesta);
            }

            mostrarAutosFechaDeUnServicio( servicios, tamS, trabajos, tamTs, autos, tam, marcas, tamM, colores, tamC, respuesta );
            break;

        // MOSTRAR TODOS LOS SERVICIOS REALIZADOS EN UNA FECHA
        case 'j':
            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            while( !validarFecha( fecha ) )
            {
                printf("ERROR. Ingrese fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            }

            mostrarServiciosEnFecha( servicios, tamS, trabajos, tamTs, fecha );
            break;



        //OPCION INVALIDA
        default:
            printf("\n\n       OPCION INVALIDA.\n\n");
            break;
    }


}


