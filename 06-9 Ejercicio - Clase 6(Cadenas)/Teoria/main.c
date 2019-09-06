#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
    strlen
    strcpy
    strupr
    strlwr
    strcmp
    stricmp
    strcat
    */
    char palabra[10];
    char palabra2[10];
    int lenght;
    int comp;
    char todo[50];
    printf("Ingrese una palabra : ");

    gets(palabra);
    lenght = strlen(palabra);
    printf("la palabra es %s y el largo es %d", palabra, lenght);
    strcpy(palabra2, "perro");
    printf("\nla palabra copiada es %s", palabra2);

    if (stricmp(palabra, palabra2)==0)
    {
        printf("\nSon iguales capo");
    }
    else
    {
        printf("\nNo CAPO NO");
    }
    strcat(todo,palabra);
    strcat(todo,palabra2);
    strcat(todo, " chau");
    printf("\nTodo : %s ", todo);

    /* Tarea:
    3 variables:
    nombre[15] = lautaro
    epellido[15] = lezama
    apellidoNombre[?] = Lezama, Lautaro (primeras letras en mayus y con coma y espacio) (solo modificar esto) */



    return 0;
}
