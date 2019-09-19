#include <stdlib.h>
#include "persona.h"
#define A 3

int main()
{
    int opcion;
    ePersonas persona[A];
    inicializarPersonas(persona, A);


    do
    {
        printf("1-Cargar personas.\n");
        printf("2-Mostrar personas.\n");
        printf("3-Ordenar por DNI\n");
        printf("4-Ordenar por Apellido y Nombre\n");
        printf("5-Salir.\n\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargaAleatoriaDePersonas(persona,A);
            break;

        case 2:
            mostrarPersona(persona, A);
            break;

        case 3:
            ordenarPorDni(persona, A);
            break;

        case 4:
            ordenarPorApellido(persona, A);
            break;
        }

        system("pause");
        system("cls");
    }
    while(opcion!=5);

    return 0;
}



