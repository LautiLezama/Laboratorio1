#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

void cargarConDatosEnterosEnteros(int[], int);
void cargarConDatosChar(char[][50], int);
int darMaximo(int[], int cantidad);
int darIndiceMax(int [], int);

int main()
{
    int notas[10];
    char nombres[TAM][50];
    int i;
    int maximo;
    int indiceMax;
    char alumnoMax[50];

    /* for(i=0; i<3; i++)
     {

         printf("\nIngrese el nombre : ");
         gets(nombres[i]);

         printf("\nIngrese su edad : ");
         scanf("%d", &notmaximo = darMaximo(nombres, notas, TAM);as[i]);

         fflush(stdin);

     } */

    cargarConDatosEnteros(notas, TAM);
    cargarConDatosChar(nombres, TAM);
    maximo = darMaximo(notas, TAM);
    indiceMax = darIndiceMax(notas, TAM);

    for (i = 0 ; i < TAM ; i ++)
    {
        printf("Su nombre es %s y se saco un %d\n", nombres[i], notas[i], 164);
    }

    strcpy(alumnoMax,nombres[indiceMax]);

    printf("El indice del pibito maximo es %d\n", indiceMax);

    printf("El mayor alumno fue %s", alumnoMax);

    return 0;
}


void cargarConDatosEnteros(int array[], int cantidad)
{
    int i;
    int aux[]= {7,10,8,2};
    for(i=0; i < cantidad; i++)
    {
        array[i] =  aux[i];
    }
}

void cargarConDatosChar(char array[][50], int cantidad)
{

    char aux[][50]= {"Alfredo", "Rogelio", "Julieta", "Pablo"};
    int i;

    for(i=0; i < cantidad; i++)
    {
        strcpy(array[i], aux[i]);
    }

}

int darMaximo(int array[], int cantidad )
{
    int i;
    int maximo;
    char maximoNombre[50];

    for (i = 0 ; i < cantidad ; i ++)
    {
        if(i == 0 || array[i] > maximo)
        {
            maximo = array[i];
        }
    }

    return maximo;
}

int darIndiceMax(int array[], int cantidad) // TAREA: Acortarlo.
{
    int i;
    int indice;
    int maximo;

    maximo = darMaximo(array, cantidad);

    for(i=0; i<cantidad; i++)
    {
        if(array[i]==maximo)
        {
            indice= i;
        }
    }

    return indice;
}


