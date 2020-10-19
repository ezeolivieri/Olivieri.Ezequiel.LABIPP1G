#ifndef EMARCA_H_INCLUDED
#define EMARCA_H_INCLUDED


typedef struct{
    int id; //Comienza en 1000
    char descripcion[20]; //Max. 20 caracteres
} eMarca;

#endif // EMARCA_H_INCLUDED

/** \brief Impresion de una estructura marca por pantalla
 *
 * \param marca eMarca
 * \return void
 *
 */
void mostrarMarca( eMarca marca );
/** \brief Muestra un array de marcas en forma de tabla por pantalla
 *
 * \param marcas[] eMarca
 * \param tam int
 * \return int
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);
/** \brief Retorna un entero que indica si es un id valido o no
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdMarca(eMarca marcas[], int tam, int id);
/** \brief Dado un id de marca obtiene su descripcion y la guarda en descripcion
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int obtenerDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);
