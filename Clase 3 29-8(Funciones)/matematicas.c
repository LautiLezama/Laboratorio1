#include "matematicas.h"

float suma(float num1, float num2)
{
    return num1 + num2;
}

float resta(float num1, float num2)
{
    return num1 - num2;
}

float dividir(float num1, float num2)
{
    return num1 / num2;
}

float multiplicar(float num1, float num2)
{
    return num1 * num2;
}

void mostrar(float resultado)
{
    printf("\nEl resultado es %f", resultado);
}

int pedirDato(int num1)
{
    scanf("%f", &num1);
    return num1;
}

void calcular(float num1, float num2, int operacion)
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
