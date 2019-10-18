#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    int edad;
    float altura;

}sPersona;

sPersona* new_Persona(); //Constructor por defecto.
int mostrarPersona(sPersona*);//Mostrar
int deletePersona(sPersona*); //Destructor
sPersona* new_Persona_Parametros(int,int,float);
