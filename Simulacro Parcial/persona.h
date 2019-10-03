#include "fecha.h"

typedef struct
{
    int idPropietario;
    char nombre[51];
    eFecha fechaNacimiento;
} ePropietario;

ePropietario pedirPropietario();
void hardcodePersonas(ePropietario [],int);
