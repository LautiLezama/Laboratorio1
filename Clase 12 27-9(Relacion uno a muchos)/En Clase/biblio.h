#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;

} sFecha;

typedef struct
{
    char patente[50];
    sFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idAuto;
} sVehiculo;

typedef struct
{
    int idPersona;
    char nombre[51];
    sFecha fechaNac;

} sPersona;

void hardcodeoAutos(sVehiculo [],int)
void hardcodePersonas(sPersona [],int)
