#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unEntero = 10 ;
    int* puntero1 = NULL;
    int* otroPuntero;

    puntero1 = &unEntero;


    printf("Ingrese un numero : ");
    scanf("%d", &unEntero);


    if(puntero1 != NULL)
    {
        otroPuntero = puntero1; //otroPuntero guarda al que apunta puntero1, no la direccion de puntero1
        printf("%d \n",unEntero);//Valor de la variable
        printf("%d \n",*puntero1);//Valor de la variable.
        printf("%d \n",*otroPuntero);//Valor de la variable.
        printf("%d \n", &unEntero);//0x40 Direccion de memoria de a donde apunta.
        printf("%d \n", puntero1);//0x40 Direccion de memoria de a donde apunta.
        printf("%d \n", &puntero1);//0x75 Direccion de memoria de puntero1
    }
    else
    {
        printf("\nNo se inicializo CAPO\n");
    }

    return 0;
}
