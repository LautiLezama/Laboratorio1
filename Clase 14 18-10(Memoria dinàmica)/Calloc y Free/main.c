#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pEntero = (int*)calloc(sizeof(int),5);
    int i;

    free(pEntero); //Libera el espacio de memoria, sirve por ej para los auxiliares.

    for(i=0;i<5;i++)
    {
        printf("%d-",*(pEntero+i));
    }

    return 0;
}
