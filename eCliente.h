#ifndef ECLIENTE_H_INCLUDED
#define ECLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[15];
    char sexo;
} eCliente;

#endif // ECLIENTE_H_INCLUDED

/** \brief Dado un id de cliente obtiene su nombre y lo guarda en nombreCliente
 *
 * \param cliente[] eCliente
 * \param tam int
 * \param id int
 * \param nombreCliente[] char
 * \return int
 *
 */
int obtenerNombreCliente(eCliente clientes[], int tam, int id, char nombreCliente[]);

/** \brief Impresion de una estructura cliente por pantalla
 *
 * \param cliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);

/** \brief Muestra un array de clientes en forma de tabla por pantalla
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int mostrarClientes(eCliente clientes[], int tam);
