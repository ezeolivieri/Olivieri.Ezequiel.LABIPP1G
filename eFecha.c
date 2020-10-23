#include "eFecha.h"

int esLaMismaFecha( eFecha fecha1, eFecha fecha2 )
{
    int iguales = 0;

    if( (fecha1.dia == fecha2.dia) &&
        (fecha1.mes == fecha2.mes) &&
        (fecha1.anio == fecha2.anio) )
    {
        iguales = 1;
    }

    return iguales;
}
