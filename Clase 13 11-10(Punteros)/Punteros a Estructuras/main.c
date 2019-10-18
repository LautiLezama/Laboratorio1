#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define A 2

typedef struct
{
    int ent;
    float b;
    char c;
} sDato;

void cargarDatos(sDato* ,int);
void mostrarDatos(sDato* , int);

int main()
{
    /*sDato unDato = {1,5.3,'B'};
      sDato* pDato;

      pDato = &unDato;

      printf("%d -- %f -- %c" ,pDato->a
                              ,pDato->b
                              ,pDato->c);*/

    sDato unDato[A];

    int i;

    cargarDatos(unDato, A);

    mostrarDatos(unDato, A);

    return 0;
}

void cargarDatos(sDato* list,int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("\nIngrese entero : ");
        scanf("%d",&(list+i)->ent);
        printf("Ingrese flotante : ");
        scanf("%f",&(list+i)->b);
        fflush(stdin);
        printf("Ingrese caracter : ");
        //scanf("%c",&(pDato+i)->c);
        (list+i)->c = getche();
        printf("\n");
    }
}

void mostrarDatos(sDato* list, int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("\n%d -- %f -- %c \n"
               ,(list+i)->ent
               ,(list+i)->b
               ,(list+i)->c);
    }
}

/*
LOS PUNTEROS SOLO GUARDAN DIRECCIONES DE MEMORIA CAPO ACORDATE.
LOS PARENTESIS SON PARA DAR PRIORIDAD, EN ESTE CASO PRIORIZO EL PUNTERO Y LUEGO BUSCO EL .A .B .C
NO HACE FALTA EL & CUANDO ES UN VECTOR A UN PUNTERO.
+1 +2 +ETC PARA MOVERSE POR LAS DIRECCIONES DE MEMORIA.
* OPERADOR DE INDIRECCION
& OPERADOR DE DIRECCION
-> OPERADOR DE ACCESO

*/
