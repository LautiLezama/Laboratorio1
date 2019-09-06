#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    strlen
    strcpy
    strupr
    strlwr
    strcmp
    stricmp
    strcat
    Lezama, Lautaro
    */

int main()
{
    char nombre[15]="lautaro";
    char apellido[15]="lezama";
    char apellidoNombre[35];
    int largo;

   /* printf("Ingrese su nombre : ");

    gets(nombre);

    printf("Ingrese su apellido : ");

    gets(apellido); */

    strcat(apellidoNombre, apellido);

    strcat(apellidoNombre, ", ");

    strcat(apellidoNombre, nombre);

    largo = strupr(apellidoNombre[15] - apellidoNombre[14]);

    printf("\n%s %d", apellidoNombre, largo);












    return 0;
}
