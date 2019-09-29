#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0


typedef struct
{
    //Campos
    int legajo;
    char nombre[50];
    int nota;
    int dni;
    int estado;

} sAlumno; //Datos de un alumno.

void mostrarAlumno(sAlumno);
sAlumno pedirAlumno();
int compararAlumnoByLegajo(sAlumno, sAlumno);
int cargarAlumnos(sAlumno[], int);
void mostrarListadoDeAlumnos(sAlumno [], int);
void ordenarAlumnosByNombre(sAlumno[], int);
int inicializarAlumnos(sAlumno[], int);
int buscarLibre(sAlumno[], int);
int buscarAlumnoPorLegajo(sAlumno*, int, int);
int darBajaPorLegajo(sAlumno*,int);
int modificarAlumnoPorLegajo(sAlumno*, int);


//Funciones para probar.
void hardcodearAlumnos(sAlumno[], int);
