#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char sexo;
    float altura;

}sPersona;

sPersona* new_Persona_Parametros(int,char,float); //Constructor parametrizado
sPersona* new_Persona(); //Constructor por defecto.
int mostrarPersona(sPersona*);
int deletePersona(sPersona*);
int setLegajo(sPersona* unaPersona, int legajo); //Escritura.
int getLegajo(sPersona*); //Lectura.
