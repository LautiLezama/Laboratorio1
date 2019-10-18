#include "persona.h"
#define A 5



int main()
{
    sPersona* listPersonas;
    listPersonas = new_Persona_Parametros(100,40,1.87);

    if(mostrarPersona(listPersonas)!=0)
    {
        printf("\n\nNo se pudo mostrar.\n\n");
    }
    if(deletePersona(listPersonas)==0)
    {
        printf("\nBorradisimo capo.\n");
    }
    else
    {
        printf("\nError al borrar.\n");
    }


    return 0;
}




