#include <stdio.h>
#include <stdlib.h>
#define tam 5

int main()
{
    int* miVector;
    int* auxVector;
    int x;

    miVector = (int*)malloc(sizeof(int)*tam);

    if(miVector != NULL)
    {
        for(x=0; x<tam; x++)
        {
            *(miVector+x) = x+1;
            printf("%d \n",*(miVector+x));
        }

        miVector = (int*)realloc(miVector,sizeof(int)*(tam-3));

        printf("\nCon menos memoria \n\n");
        for(x=0; x<tam-3; x++) //Se continuan los for.
        {
            *(miVector+x) = x+1;

            printf("%d \n",*(miVector+x));
        }

    }
    else
    {
        printf("\nNo hay mas espacio master\n");
    }

    return 0;
}

/*
REALLOC = RESERVAR X ESPACIOS MAS DE MEMORIA APARTIR DEL VECTOR YA RESERVADO(SIN OLVIDAR).
3 Situaciones con realloc : a) Encuentra espacio al toque y lo agrega.
b)No encuentra espacio al toque pero redirige(cambia la direccion de memoria) y agrega
c)No encuentra y devuelve NULL(Hace if para validar O SE RE PUDRE).

Si agregamos memoria el for continua.

Si reducimos memoria el for se reinicia.

*/
