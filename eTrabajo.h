#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED

#include "eFecha.h"

typedef struct{
    int id; //Autoincremental
    char patente[8]; //debe existir. VALIDAR
    int idServicio; //debe existir. VALIDAR
    eFecha fecha; //Validar dia, mes y anio
    int isEmpty;
} eTrabajo;

#endif // ETRABAJO_H_INCLUDED

#include "eAuto.h"
#include "eServicio.h"
#include "eMarca.h"
#include "eColor.h"

/** \brief Inicializa los trabajos poniendo el atributo isEmpty en 1
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief Retorna el indice de un lugar libre dentro de un array de trabajos
 *
 * \param works[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int buscarWorkLibre(eTrabajo works[], int tam);

/** \brief Muestra un array de Trabajos en forma de tabla por pantalla
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param autos[] eAuto
 * \param tamA int
 * \param servicios[] eServicio
 * \param tamS int
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam, eAuto autos[], int tamA, eServicio servicios[], int tamS);

/** \brief Impresion de una estructura Trabajo por pantalla
 *
 * \param trabajo eTrabajo
 * \param autos[] eAuto
 * \param tamA int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS);

/** \brief Alta de una estructura Trabajo
 *
 * \param works[] eTrabajo
 * \param tam int
 * \param autos[] eAuto
 * \param tamN int
 * \param servicios[] eServicio
 * \param tamS int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param idWork int
 * \return int
 *
 */
int altaTrabajo(eTrabajo works[], int tam, eAuto autos[], int tamN, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC, int idWork, eCliente clientes[], int tamClientes);

