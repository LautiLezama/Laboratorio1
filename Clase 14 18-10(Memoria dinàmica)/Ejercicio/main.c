#include "persona.h"
#define CANT 3



int main()
{
    sPersona* listPersonas[CANT];
    int i;
    int legajo;
    char sexo;
    float altura;
    sPersona* unaPersona;
    for(i=0; i<CANT; i++)
    {
        unaPersona = new_Persona();
        printf("Ingrese legajo : ");
        scanf("%d",&legajo);
        printf("Ingrese sexo : ");
        sexo = getche();
        printf("\n");
        printf("Ingrese altura : ");
        scanf("%f",&altura);
        printf("\n\n");
        unaPersona = new_Persona_Parametros(legajo,sexo,altura);
        listPersonas[i]=unaPersona;
    }

    for(i=0;i<CANT;i++)
    {
        mostrarPersona(listPersonas[i]);
    }

    return 0;
}




