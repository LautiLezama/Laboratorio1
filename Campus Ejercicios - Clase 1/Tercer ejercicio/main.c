#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int contadorPos = 0;
    int contadorNeg = 0;

    for(int contador=0; contador < 10; contador ++)
    {

        printf("Ingrese un numero : ");
        scanf("%d", &num1);

        if (num1 >= 0)
        {

            contadorPos ++;
        }
        else
        {

            contadorNeg ++;

        }
    }

    printf("Hay %d numeros positivos y %d numeros negativos.", contadorPos, contadorNeg);
}
