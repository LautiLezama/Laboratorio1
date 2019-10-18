#include "persona.h"


sPersona* new_Persona() //funcion para inicializar?
{
    sPersona* unaPersona;

    unaPersona = calloc(sizeof(sPersona),1); //Siempre inicializar una unidad de la estructura con malloc para reservar bytes.

    return unaPersona;
}

int mostrarPersona(sPersona* unaPersona)
{
    int i;
    int r = -1;
    if(unaPersona != NULL)
    {
        printf("La persona es : \n\n");
        printf("%d -- %d -- %f \n",
               unaPersona->legajo,
               unaPersona->edad,
               unaPersona->altura);
        r = 0;
    }
    return r;
}

int deletePersona(sPersona* unaPersona)
{
    int r = -1;
    if(unaPersona != NULL)
    {
        free(unaPersona);
        r = 0;
    }
    return r;
}

sPersona* new_Persona_Parametros(int legajo,int edad,float altura)
{
    sPersona* unaPersona = new_Persona();

    if(unaPersona!=NULL)
    {
        unaPersona->legajo = legajo;
        unaPersona->edad = edad;
        unaPersona->altura = altura;
    }
    return unaPersona;
}
