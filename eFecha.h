#ifndef EFECHA_H_INCLUDED
#define EFECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
} eFecha;

#endif // EFECHA_H_INCLUDED

/** \brief Retorna 1 si fecha1 es igual a fecha2, sino retorna 0
 *
 * \param fecha1 eFecha
 * \param fecha2 eFecha
 * \return int
 *
 */
int esLaMismaFecha( eFecha fecha1, eFecha fecha2 );
