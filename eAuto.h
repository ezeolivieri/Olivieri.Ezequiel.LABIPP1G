#ifndef EAUTO_H_INCLUDED
#define EAUTO_H_INCLUDED


typedef struct{
    int id;
    char patente[8];
    int idMarca; //Validar
    int idColor; //Validar
    int modelo; //Año de fabricacion
    int isEmpty;
} eAuto;
#include "eMarca.h"
#include "eColor.h"

#endif // EAUTO_H_INCLUDED

/** \brief Inicializa los autos poniendo el atributo isEmpty en 1
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int
 *
 */
int inicializarAutos(eAuto autos[], int tam);

/** \brief Retorna el indice de un lugar libre dentro de un array de autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int
 *
 */
int buscarAutoLibre(eAuto autos[], int tam);

/** \brief Alta de una estructura auto
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param idAuto int
 * \return int
 *
 */
int altaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int idAuto);

/** \brief Retorna el indice del auto buscado
 *
 * \param autos[] eAuto
 * \param tam int
 * \param idAuto int
 * \return int
 *
 */
int buscarAuto(eAuto autos[], int tam, int idAuto);

/** \brief Muestra un array de Autos en forma de tabla por pantalla
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int mostrarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC );
/** \brief Impresion de una estructura auto por pantalla
 *
 * \param car eAuto
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return void
 *
 */
void mostrarAuto(eAuto car, eMarca marcas[], int tamM, eColor colores[], int tamC);

/** \brief Modificacion de una estructura auto
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
/** \brief Baja lógica de una estructura auto
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int bajaAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);

/** \brief Dada una patenteBuscar, se busca y de encontrarse se guarda en patenteGuardar
 *
 * \param autos[] eAuto
 * \param tam int
 * \param patenteBuscar[] char
 * \param patenteGuardar[] char
 * \return int
 *
 */
int obtenerPatenteAuto(eAuto autos[], int tam, char patenteBuscar[], char patenteGuardar[]);

/** \brief Retorna un entero indicando si es una patente de Auto valida o no
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param patente[] char
 * \return int
 *
 */
int validarPatenteAuto(eAuto autos[], int tamA, char patente[]);

/** \brief Dada una list de autos, se ordena por Marca y Patente
 *
 * \param list[] eAuto
 * \param tam int
 * \return int
 *
 */
int ordenarAutosPorMarcaPatente(eAuto autos[], int tam, eMarca marcas[], int tamM);
/** \brief Swapeo de estructuras eAuto
 *
 * \param a eAuto*
 * \param b eAuto*
 * \return int
 *
 */
int autoSwap(eAuto* a, eAuto* b);
