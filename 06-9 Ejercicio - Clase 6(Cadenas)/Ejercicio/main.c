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
    char nombre[15];
    char apellido[15];
    char apellidoNombre[35];
    int i;
    int largo;

     printf("Ingrese su nombre : ");

     gets(nombre);

     printf("Ingrese su apellido : ");

     gets(apellido);

    strcat(apellidoNombre, apellido);

    strcat(apellidoNombre, ", ");

    strcat(apellidoNombre, nombre);

    largo = strlen(apellidoNombre);

    apellidoNombre[0]-= 32;

    for (i = 0; i < largo; i++)
    {
        if(apellidoNombre[i] == 32)
        {
            i ++;
            apellidoNombre[i] -=32;


        }

    }


    printf("%s", apellidoNombre);


    return 0;
}
