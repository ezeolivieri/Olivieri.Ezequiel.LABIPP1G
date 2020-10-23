#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "eAuto.h"
#include "eCliente.h"
#include "eColor.h"
#include "eFecha.h"
#include "eMarca.h"
#include "eServicio.h"
#include "eTrabajo.h"

#endif // VALIDACIONES_H_INCLUDED

/** \brief Retorna un entero indicando si es una patente de Auto valida o no
 *
 * \param autos[] eAuto
 * \param tamA int
 * \param patente[] char
 * \return int
 *
 */
int validarPatenteAuto(eAuto autos[], int tamA, char patente[]);

/** \brief Retorna 1 si tiene el formato correcto de una patente nueva
 *
 * \param patente[] char
 * \return int
 *
 */
int tieneFormatoDePatente( char patente[] );

/** \brief Valida id buscandolo en autos y retorna un entero que representa si se encontro o no
 *
 * \param autos[] eAuto
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdAuto(eAuto autos[], int tam, int id);

/** \brief Retorna un entero que indica si es un id valido o no
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdCliente(eCliente clientes[], int tam, int id);

/** \brief Retorna un entero que indica si es un id valido o no
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdColor(eColor colores[], int tam, int id);

/** \brief Valida que sea una fecha correcta
 *
 * \param fecha eFecha
 * \return int
 *
 */
int validarFecha( eFecha fecha );

/** \brief Retorna un entero que indica si es un id valido o no
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdMarca(eMarca marcas[], int tam, int id);

/** \brief Retorna un entero indicando si es un id de Servicio valido o no
 *
 * \param servicios[] eServicio
 * \param tamS int
 * \param id int
 * \return int
 *
 */
int validarIdServicio( eServicio servicios[], int tamS, int id );

