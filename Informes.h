#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "eAuto.h"
#include "eMarca.h"
#include "eColor.h"
#include "eCliente.h"
#include "eTrabajo.h"
#include "eServicio.h"
#include "eFecha.h"

#endif // INFORMES_H_INCLUDED

/** \brief Dado un idColor, se muestra en forma de tabla los autos ingresados de ese color
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \param idColor int
 * \return void
 *
 */
void mostrarAutosDeUnColor( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes, int idColor );

/** \brief Dado un idMarca, se muestra en forma de tabla los autos ingresados de esa marca
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \param idMarca int
 * \return void
 *
 */
void mostrarAutosDeUnaMarca( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes, int idMarca );

/** \brief Muestra un informe de el o los autos más viejos
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return void
 *
 */
void mostrarAutosMasViejos( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes );

/** \brief Retorna un entero que representa el modelo mas antiguo de una lista de autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int
 *
 */
int modeloMasAntiguo( eAuto autos[], int tam );

/** \brief Muestra una tabla por cada marca de auto ingresado
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return void
 *
 */
void mostrarAutosSeparadoPorMarcas( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes );

/** \brief Dado un marcaId retorna un entero que representa la cantidad de autos con ese marcaId
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcaId int
 * \return int
 *
 */
int cantAutosDeMarca( eAuto autos[], int tam, int marcaId );

/** \brief Muestra por pantalla la cantidad de autos con idColor y idMarca
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \param idColor int
 * \param idMarca int
 * \return void
 *
 */
void mostrarCantidadAutosDeUnColorYMarca( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes, int idColor, int idMarca );

/** \brief Muestra en forma de tabla las marcas mas elegidas por los clientes
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return void
 *
 */
void mostrarMarcasMasElegidas( eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamClientes );

/** \brief Retorna un entero que representa la cantidad de autos ingresados con la marca mas elegida
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \return int
 *
 */
int cantAutosConMarcaMasElegida( eAuto autos[], int tam, eMarca marcas[], int tamM );

/** \brief Despliega una tabla con los trabajos hechos al auto con idAuto
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param autos[] eAuto
 * \param tamA int
 * \param servicios[] eServicio
 * \param tamS int
 * \param idAuto int
 * \return void
 *
 */
void mostrarTrabajosHechosAUnAuto( eTrabajo trabajos[], int tam, eAuto autos[], int tamA, eServicio servicios[], int tamS, int idAuto );

/** \brief Muestra la suma de importes hechos al auto con idAuto
 *
 * \param trabajos[] eTrabajo
 * \param tamTs int
 * \param servicios[] eServicio
 * \param tamS int
 * \param autos[] eAuto
 * \param tam int
 * \param idAuto int
 * \return void
 *
 */
void sumaDeImportesHechosAUnAuto( eTrabajo trabajos[], int tamTs, eServicio servicios[], int tamS, eAuto autos[], int tam, int idAuto );

/** \brief Despliega una tabla con informacion del auto y la fecha dado un idServicio
 *
 * \param servicios[] eServicio
 * \param tamS int
 * \param trabajos[] eTrabajo
 * \param tamTs int
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param idServicio int
 * \return void
 *
 */
void mostrarAutosFechaDeUnServicio( eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int idServicio );

/** \brief Muestra una tabla de servicios que contengan la fecha indicada
 *
 * \param servicios[] eServicio
 * \param tamS int
 * \param trabajos[] eTrabajo
 * \param tamTs int
 * \param fecha eFecha
 * \return void
 *
 */
void mostrarServiciosEnFecha( eServicio servicios[], int tamS, eTrabajo trabajos[], int tamTs, eFecha fecha );

