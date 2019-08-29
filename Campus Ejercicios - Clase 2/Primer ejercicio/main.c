#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int maximo;
    int minimo;
    int acumulador = 0;
    float promedio;
    int contador = 0;

    for( ; contador < 5; contador ++)
    {
        printf("Ingrese un numero : ");
        scanf("%d",&num1);

        if (contador == 0)
        {
            maximo = num1;
            minimo = num1;
        }

        if (num1 > maximo)
        {
            maximo = num1;
        }

        if (num1 < minimo)
        {
            minimo = num1;
        }

        acumulador = acumulador + num1;
    }

    promedio = (float)acumulador / contador;

    printf("El promedio es %f , el minimo es %d y el maximo es %d", promedio, minimo, maximo);




}
