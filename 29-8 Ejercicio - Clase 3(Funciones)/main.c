#include "matematicas.h"

void saludar();



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



