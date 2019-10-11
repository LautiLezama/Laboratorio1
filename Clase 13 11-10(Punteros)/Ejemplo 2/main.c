#include <stdio.h>
#include <stdlib.h>
#define A 5

void cargarVector(int*,int);
void mostrarVector(int*,int);
void incrementarId(int*);

int main()
{
    int vector[A];
    int contID = 0;

    cargarVector(vector, A);
    mostrarVector(vector, A);
    incrementarId(&contID);
    printf("%d \n", contID);

    return 0;
}

void cargarVector(int* vector,int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("Ingrese un numero : ");
        scanf("%d",vector+i);
    }

}

void mostrarVector(int* vector,int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("%d \n", *(vector + i));
    }
}

void incrementarId(int* ultimoId)
{
    *ultimoId = *ultimoId + 1;
}
/*TRABAJAR SOLO CON PUNTEROS,NO CON NOTACION DE VECTOR.


*/
