#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED

typedef struct{
    int id; //Comienza en 5000
    char nombreColor[20]; //Max. 20 caracteres
} eColor;

#endif // ECOLOR_H_INCLUDED

/** \brief Impresion de una estructura color por pantalla
 *
 * \param color eColor
 * \return void
 *
 */
void mostrarColor(eColor color);
/** \brief Muestra un array de colores en forma de tabla por pantalla
 *
 * \param colores[] eColor
 * \param tam int
 * \return int
 *
 */
int mostrarColores(eColor colores[], int tam);
/** \brief Retorna un entero que indica si es un id valido o no
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdColor(eColor colores[], int tam, int id);



/** \brief Dado un id de color obtiene su nombre y lo guarda en nombreColor
 *
 * \param colores[] eColor
 * \param tam int
 * \param id int
 * \param nombreColor[] char
 * \return int
 *
 */
int obtenerNombreColor(eColor colores[], int tam, int id, char nombreColor[]);
