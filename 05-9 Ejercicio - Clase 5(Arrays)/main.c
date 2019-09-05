#include <stdio.h>
#include <stdlib.h>
void mostrarArray(int myArray[], int cantidad);
int darMaximo(int myArray[], int cantidad);
int darMinimo(int myArray[], int cantidad);
int inicializarArray(int myArray[], int cantidad);
int cargaSecuencialArray(int myArray[], int cantidad, char mensaje[]);
int darPromedio(int myArray[], int cantidad);
void OrdenarMenorMayor(int myArray[], int cantidad);
void OrdenarMayorMenor(int myArray[], int cantidad);

int main()
{

    int listadoDeNumeros[6];
    int maximo;
    int minimo;
    float promedio;


    cargaSecuencialArray(listadoDeNumeros, 6, "Ingrese su edad : ");

    mostrarArray(listadoDeNumeros, 6);

    promedio = darPromedio(listadoDeNumeros, 6);

    maximo = darMaximo(listadoDeNumeros, 6);

    minimo = darMinimo(listadoDeNumeros, 6);

    printf("\nDe menor a mayor\n");

    OrdenarMenorMayor(listadoDeNumeros, 6);

    mostrarArray(listadoDeNumeros, 6);

    printf("\nDe mayor a menor\n");

    OrdenarMayorMenor(listadoDeNumeros, 6);

    mostrarArray(listadoDeNumeros, 6);

    printf("\nEl maximo es %d", maximo);
    printf("\nEl minimo es %d", minimo);
    printf("\nEl promedio es %f", promedio);

    return 0;
}

void mostrarArray(int myArray[], int cantidad)
{
    int i;

    for (i = 0 ; i < cantidad ; i ++)
    {
        printf("%d\n", myArray[i]);
    }
}

int darMaximo(int myArray[], int cantidad)
{
    int i;
    int maximo;

    for (i = 0 ; i < cantidad ; i ++)
    {
        if(i == 0 || myArray[i] > maximo)
        {
            maximo = myArray[i];
        }
    }

    return maximo;
}

int darMinimo(int myArray[], int cantidad)
{
    int i;
    int minimo;
    for (i = 0 ; i < cantidad ; i ++)
    {
        if(i == 0 || myArray[i] < minimo)
        {
            minimo = myArray[i];
        }
    }
    return minimo;
}


int cargaSecuencialArray(int myArray[], int cantidad, char mensaje[])
{
    int i;
    for(i=0 ; i < cantidad ; i++)
    {
        printf(mensaje);
        scanf("%d", &myArray[i]);
    }

    return myArray;
}

int darPromedio(int myArray[], int cantidad)
{
    int i;
    int acumulador = 0;
    float promedio;

    for(i=0 ; i < cantidad ; i++)
    {
        acumulador = acumulador + myArray[i];
    }

    promedio = (float)acumulador / cantidad;
    return promedio;
}

void OrdenarMenorMayor(int myArray[], int cantidad)
{
    int i;
    int j;
    int aux;

    for(i=0 ; i < cantidad ; i++)
    {
        for(j=i+1 ; j < cantidad ; j++)
        {
         if(myArray[i] > myArray[j])
         {
             aux = myArray[i];
             myArray[i]=myArray[j];
             myArray[j]=aux;
         }
        }
    }

}

void OrdenarMayorMenor(int myArray[], int cantidad)
{
   int i;
    int j;
    int aux;

    for(i=0 ; i < cantidad ; i++)
    {
        for(j=i+1 ; j < cantidad ; j++)
        {
         if(myArray[i] < myArray[j])
         {
             aux = myArray[i];
             myArray[i]=myArray[j];
             myArray[j]=aux;
         }
        }
    }
}
