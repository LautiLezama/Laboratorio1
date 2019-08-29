#include <stdio.h>
#include <stdlib.h>
void saludar();
void calcular(int num1, int num2, int operacion);
float suma(int num1, int num2);
float resta(int num1, int num2);
float dividir(int num1, int num2);
float multiplicar(int num1, int num2);
void mostrar(float resultado);
int pedirDato(int num1);

int main()
{
    printf("Ingrese que operacion desea hacer: \n1- Sumar");

    printf("\n2-Restar\n3-Multiplicar\n4-Dividir\n");

    int operacion = pedirDato(operacion);

    printf("\nIngrese el primer numero: ");

    int numero1 = pedirDato(numero1);

    printf("\nIngrese el segundo numero: ");

    int numero2 = pedirDato(numero2);

    calcular(numero1,numero2,operacion);

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
