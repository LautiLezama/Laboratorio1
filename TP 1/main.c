#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1;
    float num2;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDiv;
    float resultadoMult;


    printf("El primer numero : ");
    scanf("%f", &num1);

    printf("El segundo numero : ");
    scanf("%f", &num2);

    // Suma

    resultadoSuma = num1 + num2;

    // Resta

    resultadoResta = num1 - num2;

    // Division

    resultadoDiv = num1 / num2;

    // Multiplicacion

    resultadoMult = num1 * num2;

    printf("El resultado de la suma es : %f", resultadoSuma);
    printf("\nEl resultado de la resta es : %f", resultadoResta);

    // Validacion del divisor.

    if(num2 == 0)
    {

        printf("\nNo es posible dividir por cero");
    }
    else
    {

        printf("\nEl resultado de la division es : %f", resultadoDiv);

    }

    printf("\nEl resultado de la multiplicacion es : %f", resultadoMult);








}
