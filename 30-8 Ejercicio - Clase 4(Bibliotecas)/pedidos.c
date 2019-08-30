#include "pedidos.h"



int pedirEntero(char msj[], int min, int max)
{
    int unNumero;
    printf("%s",msj);
    scanf("%d", &unNumero);
    while(unNumero>max || unNumero<min)
    {
        printf("ERROR %s", msj);
        scanf("%d", &unNumero);
    }
    return unNumero;
}
