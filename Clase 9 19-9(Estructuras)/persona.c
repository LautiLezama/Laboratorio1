#include "persona.h"
#include <string.h>

void pedirPersona(ePersonas persona[], int cant)
{
    int auxDni;
    printf("Ingrese DNI sin puntos: ");
    scanf("%d", &auxDni);

    while(validarDni(persona, auxDni, cant)==1)
    {
        printf("Ya ingreso este DNI, ingrese otro : ");
        scanf("%d", &auxDni);
    }

    persona[cant].dni = auxDni;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(persona[cant].nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(persona[cant].apellido);

    persona[cant].estaVacio = 0;

}

void mostrarPersona(ePersonas persona[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(persona[i].estaVacio == 0)
    {
        printf("%s---%s---%d\n\n", persona[i].nombre, persona[i].apellido, persona[i].dni);
    }
    }

}

void cargarListadoDePersonas(ePersonas lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        pedirPersona(lista,i);
    }
}

void inicializarPersonas(ePersonas lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        lista[i].estaVacio = 1;
    }
}

void cargaAleatoriaDePersonas(ePersonas lista[], int cant)
{
    int i;
    int flagEncontro = 0;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estaVacio==1)
        {
            pedirPersona(lista, i);
            flagEncontro = 1;
            break;
        }
    }

    if(flagEncontro==0)
    {
        printf("OCUPADO CAPO\n");
    }
}

void ordenarPorDni(ePersonas lista[], int cant)
{
    ePersonas auxPersona;
    int i;
    int j;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(lista[i].dni < lista[j].dni)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
        }
    }

}

int validarDni(ePersonas lista[], int auxDni, int cant)
{
    int i;
    int salida = 0;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estaVacio == 0 && auxDni == lista[i].dni)
        {
            salida = 1;
        }
    }
    return salida;
}

void ordenarPorApellido(ePersonas lista[], int cant)
{
    ePersonas auxApellido;
    int i;
    int j;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido) > 0)
            {
                auxApellido = lista[i];
                lista[i] = lista[j];
                lista[j] = auxApellido;
            }
        }
    }
}


