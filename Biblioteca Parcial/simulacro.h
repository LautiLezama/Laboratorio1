#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int dia;
    int mes;
    int anio;
}sFecha;

typedef struct
{
  int idPropietario;
  char nombre[51];
  sFecha fechaNacimiento;
  int estado;
}sPropietario;

typedef struct
{
    char patente[10];
    sFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idPropietario;
    int estado;
}sVehiculo;

//Funciones generales
int enterInt(int);
float enterFloat(float);
char* enterString(char*);
int positivoInt(char []);
int onlyLetters(char []);

//Primer estructura
void hardcodeoPropietarios(sPropietario [], int);
int inicializarPropietarios(sPropietario [], int);
sPropietario pedirPropietario();
int cargarPropietario(sPropietario [], int, int);
int bajarPropietario(sPropietario [], int);
int buscarLibrePropietario(sPropietario [], int);
int buscarPropietarioPorID(sPropietario [], int);
void mostrarUnPropietario(sPropietario);
void mostrarListadoDePropietarios(sPropietario [], int);
int modificarPropietario(sPropietario [],int);
int ordenarPersonasPorNombreAndAnio(sPropietario [],int);

//Segunda estructura

int inicializarVehiculos(sVehiculo [],int);
sVehiculo pedirVehiculo();
int cargarVehiculo(sVehiculo [], int);
int bajarVehiculo(sVehiculo [], sPropietario [], int);
void hardcodeoVehiculos(sVehiculo [], int);
int buscarVehiculoPorPatente(sVehiculo [], int);
void mostrarUnVehiculo(sVehiculo, sPropietario [], int);
void mostrarListadoDeVehiculos(sVehiculo [],sPropietario [], int);
int buscarLibreVehiculo(sVehiculo [], int);
int ordenarVehiculosPorDuenioAndPatente(sVehiculo [], int);

//Combinados

int mostrarVehiculosDeUnDuenio(sVehiculo [],sPropietario [], int, int);
void cobrarPorAuto(sVehiculo [],sPropietario [], int, int);














