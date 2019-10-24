#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define A 50
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    int orden;
    char apellido[51];
    int isEmpty;

} ePersona;


void inicializarPersona(ePersona*,int);
int cargarDatos(ePersona*,int,int);
void mostrarPersonas(ePersona*,int);
void swappeoPersona(ePersona*,ePersona*);
void ordenarPersonas(ePersona*,int);
void incrementarId(int*);
int buscarLibre(ePersona*,int);
int flagPersonas(ePersona*,int);
int onlyLetters(char*);

int main()
{
    ePersona listPersonas[A];
    int contId = 1;
    int opcion;
    inicializarPersona(listPersonas,A);

    do
    {
        printf("\n BIENVENIDO CAPO, CUAL TE PINTA HOY? \n\n");
        printf("1.CARGATE UN PIBE.\n");
        printf("2.ORDENAME A LOS PIBES.\n");
        printf("3.MOSTRAME A LOS PIBES.\n");
        printf("4.NOS VIMO AMIGO.\n");
        printf("777.NO AMIGO NO TOQUES ESTO.\n");
        printf("\nDALE ELEJI CAPO MAFIA : ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(cargarDatos(listPersonas,A,contId) == 0)
            {
                incrementarId(&contId);
                printf("\nCARGADISIMO CAPO.\n\n");
            }
            else
            {
                printf("\nNO HAY MAS PIBES MASTER.\n\n");
            }
            break;
        case 2:
            if(flagPersonas(listPersonas,A)==0)
            {
                ordenarPersonas(listPersonas,A);
                printf("\nORDENADISIMOS CAPO\n\n");
            }
            else
            {
                printf("\n CAPO NO CARGASTE NADA ME ESTAS BASUREANDO.\n\n");
            }
            break;
        case 3:
            if(flagPersonas(listPersonas,A)==0)
            {
                mostrarPersonas(listPersonas,A);
            }
            else
            {
                printf("\n CAPO NO CARGASTE NADA ME ESTAS BASUREANDO.\n\n");
            }
            break;
        case 4:
            break;
        case 777:
            gets(opcion);
            break;
        default:
            printf("FLASHEASTE MAL CON LA OPCION.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion != 4);




    return 0;
}

void mostrarPersonas(ePersona* list,int cant)
{
    int i;

    printf("\n\nID \t\t ORDEN \t\t\t\t APELLIDO \n\n");
    for(i=0; i<cant; i++)
    {
        if((list+i)->isEmpty == OCUPADO)
        {
            printf("%d \t\t %d \t\t    %20s \n",(list+i)->id,(list+i)->orden,(list+i)->apellido);

        }
    }
}

void ordenarPersonas(ePersona* list, int cant)
{
    int i;
    int j;
    for(i=0; i<cant-1; i++)
    {
        if((list+i)->isEmpty == OCUPADO)
        {
            for(j=i+1; j<cant; j++)
            {
                if((list+i)->orden > (list+j)->orden)
                {
                    swappeoPersona(list+i,list+j);
                }
            }
        }
    }
}

void swappeoPersona(ePersona* num1,ePersona* num2)
{
    ePersona aux;
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

void inicializarPersona(ePersona* list,int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        (list+i)->isEmpty = LIBRE;
    }
}

int cargarDatos(ePersona* list,int cant,int contId)
{
    int i;
    int r = -1;

    i = buscarLibre(list,cant);
    if(i!=-1)
    {
        printf("\nIngrese numero de orden : ");
        scanf("%d",&(list+i)->orden);
        printf("Ingrese apellido del votante : ");
        fflush(stdin);
        gets(&(list+i)->apellido);
        r = onlyLetters((list+i)->apellido);
        while(r == -2)
        {
            printf("Solo letras para el apellido master, reingresa : ");
            gets(&(list+i)->apellido);
            r = onlyLetters((list+i)->apellido);
        }
        (list+i)->id = contId;
        (list+i)->isEmpty = OCUPADO;
        r = 0;
    }

    return r;
}

void incrementarId(int* ultimoId)
{
    *ultimoId = *ultimoId + 1;
}

int buscarLibre(ePersona* list,int cant)
{

    int i;
    int index= -1;
    for(i=0; i<cant; i++)
    {
        if((list+i)->isEmpty==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;

}

int flagPersonas(ePersona* list,int cant)
{
    int r = -1;
    int i;

    for(i=0; i<cant; i++)
    {
        if((list+i)->isEmpty == OCUPADO)
        {
            r = 0;
            break;
        }
    }

    return r;
}

int onlyLetters(char* string1)
{
    int i;
    int largo;
    int r = 0;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(((*(string1+i)<97 && *(string1+i)>90) || *(string1+i)>122) || *(string1+i)<65)
        {
            r = -2;
            return r;
        }
    }
    return r;
}


int buscarProximoId(ePersona* list, int cant)
{
    int i = 0;
    int id= -1;
    for(i=0; i<cant; i++)
    {
        if((list+1)->id > id)
        {
            id = (list+i)->id;
        }
    }
    return id+1;
}
