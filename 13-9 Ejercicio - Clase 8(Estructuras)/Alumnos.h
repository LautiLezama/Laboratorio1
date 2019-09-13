#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    //Campos
    int legajo;
    char nombre[50];
    int nota;
    int dni;

} sAlumno; //Datos de un alumno.

void mostrarAlumno(sAlumno);
sAlumno pedirAlumno();
int compararAlumnoByLegajo(sAlumno, sAlumno);
void cargarAlumnos(sAlumno[], int);
void mostrarListadoDeAlumnos(sAlumno [], int);
void ordenarAlumnosByNombre(sAlumno[], int);

//Funciones para probar.
void hardcodearAlumnos(sAlumno[], int);
