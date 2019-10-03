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

void hardcodePersonas(sPersona [],int);
void mostrarPersonas(sPersona [],int);
void hardcodeoAutos(sVehiculo [],int);
void mostrarAutitos(sVehiculo [],sPersona [],int);
int buscarPorPatente(sVehiculo [],int);
void mostrarUnAutito(sVehiculo, sPersona[], int);
void mostrarUnaPersona(sPersona);
int buscarPersonaById(sPersona[], int);
void mostrarAutosByDuenio(sVehiculo[],sPersona[],int,int);
void mostrarDueniosAndAutos(sVehiculo [], sPersona[], int);
void cobrarPorAuto(sVehiculo [],sPersona[], int);
void cobrarPorDuenio(sVehiculo [], sPersona[], int);
