#include "pedidos.h"
#include <stdlib.h>
int factorial(int); //Funcion de factorial nada que ver para probar.

int main()
{
    int resultado;

    resultado = factorial(5);

    printf("El factorial es %d\n", resultado);


    int edad = pedirEntero("ingrese edad ",1,100);
    int legajo = pedirEntero("ingrese legajo ",0,2000);
    int nota = pedirEntero("ingrese nota ",1,10);
    int documento = pedirEntero("ingrese documento ",0,10000);

    printf("%d--%d--%d--%d\n\n", edad,legajo,nota,documento );

    return 0;
}

int factorial(int numero)
{
    int resultado;

    if(numero==0)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero * factorial(numero-1);
    }

    return resultado;
}
