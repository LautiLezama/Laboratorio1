#include "fecha.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    int idPropietario;
    char nombre[51];
    eFecha fechaNacimiento;
} ePropietario;

typedef struct
{
    char patente[10];
    eFecha fechaIngreso;
    int horaEntrada;
    int horaSalida;
    ePropietario idPropietario;

} eVehiculo;

ePropietario pedirPropietario();
void hardcodePersonas(ePropietario [],int);
void ordenarByNombreAndAnio(ePropietario [],int);
void mostrarListadoPersonas(ePropietario [], int);
void hardcodeAutos(eVehiculo [], int);
void mostrarListadoAutos(eVehiculo [],ePropietario[], int);
void ordenarByDuenioAndPatente(eVehiculo [],ePropietario [], int);

