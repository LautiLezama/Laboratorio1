#include <stdio.h>
typedef struct
{
 int dni;
 char nombre[50];
 char apellido[50];
 int estaVacio;
}ePersonas;

void pedirPersona(ePersonas [], int);
void cargaAleatoriaDePersonas(ePersonas [], int );
void mostrarPersona(ePersonas [], int);
void cargaSecuencialDePersonas(ePersonas [], int);
void mostrarListadoDePersonas(ePersonas [], int);
void inicializarPersonas(ePersonas [], int);
void ordenarPorDni(ePersonas [], int);
int validarDni(ePersonas [], int, int);
void ordenarPorApellido(ePersonas [], int);
