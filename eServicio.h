#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED

typedef struct{
    int id; //Comienza en 20000
    char descripcion[25]; //Max. 25 caracteres
    float precio;
} eServicio;

#endif // ESERVICIO_H_INCLUDED

/** \brief Muestra un array de Servicios en forma de tabla por pantalla
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return int
 *
 */
int mostrarServicios(eServicio servicios[], int tam);
/** \brief Impresion de una estructura Servicio por pantalla
 *
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief Dado un id de un servicio, se guarda su descripcion en descripcion
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int obtenerDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);
/** \brief Retorna un entero indicando si es un id de Servicio valido o no
 *
 * \param servicios[] eServicio
 * \param tamS int
 * \param id int
 * \return int
 *
 */
int validarIdServicio( eServicio servicios[], int tamS, int id );
