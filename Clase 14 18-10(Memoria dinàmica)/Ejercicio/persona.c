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
        printf("%d -- %c -- %f \n",
               unaPersona->legajo,
               unaPersona->sexo,
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

sPersona* new_Persona_Parametros(int legajo,char sexo,float altura)
{
    sPersona* unaPersona = new_Persona();

    if(unaPersona!=NULL)
    {
        unaPersona->legajo = legajo;
        unaPersona->sexo = sexo;
        unaPersona->altura = altura;
    }
    return unaPersona;
}

int setLegajo(sPersona* unaPersona, int legajo)
{
    int r = -1;
    if(unaPersona != NULL && legajo>0)
    {
        unaPersona->legajo=legajo;
        r = 0;
    }
    return r;
}

int getLegajo(sPersona* unaPersona)
{
    int legajo = -1;
    if(unaPersona != NULL)
    {
        legajo = unaPersona->legajo;
    }
}
