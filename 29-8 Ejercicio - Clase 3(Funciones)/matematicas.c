#include "matematicas.h"

float suma(int num1, int num2)
{
    return num1 + num2;
}

float resta(int num1, int num2)
{
    return num1 - num2;
}

float dividir(int num1, int num2)
{
    return num1 / num2;
}

float multiplicar(int num1, int num2)
{
    return num1 * num2;
}

void mostrar(float resultado)
{
    printf("\nEl resultado es %f", resultado);
}

int pedirDato(int num1)
{
    scanf("%d", &num1);
    return num1;
}

void calcular(int num1, int num2, int operacion)
{
    float resultado;

    switch(operacion)
    {
    case 1:
        resultado = suma(num1, num2);
        break;

    case 2:
        resultado = resta(num1, num2);
        break;

    case 3:
        resultado = multiplicar(num1, num2);
        break;

    case 4:
        resultado = dividir(num1, num2);
        break;


    }
    mostrar(resultado);
}
