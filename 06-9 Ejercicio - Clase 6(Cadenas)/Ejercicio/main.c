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
    int i;
    int largo;

   /* printf("Ingrese su nombre : ");

    gets(nombre);

    printf("Ingrese su apellido : ");

    gets(apellido); */

    largo = strlen(apellidoNombre);

    strcat(apellidoNombre, apellido);

    strcat(apellidoNombre, ", ");

    strcat(apellidoNombre, nombre);

    printf("\n%s", apellidoNombre);

    for(i=0;i<largo;i++)
    {
        if (strcmp(apellidoNombre[i], "l")==0)
        {
            strupr(apellidoNombre[i]);
        }
    }

     printf("\n%s", apellidoNombre);












    return 0;
}
