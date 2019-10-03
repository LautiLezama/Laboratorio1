#include <stdio.h>
#include <stdlib.h>
#include "asd.h"

#define P 4
#define V 10

int main()
{
    ePropietario listaPropietarios;
    eVehiculo listaVehiculos;
    int opcion;
    int i;

    hardcodePersonas(listaPropietarios, P);

    do
    {
        printf("1. Todas las personas ordenadas por nombre y año de nacimiento\n");
        printf("2. Todos los vehículos ordenados por dueño y patente.\n");
        printf("3. Cada auto con el nombre de su dueño.\n");
        printf("4. Por cada dueño los autos que tiene estacionados.\n");
        printf("5. Ingresar un dueño y mostrar todos sus autos.\n");
        printf("6. Mostrar el total de la estadía de cada auto, sabiendo que el valor hora es $100.\n");
        printf("7. Mostrar cuanto deberá pagar cada dueño por todos sus autos estacionados.\n");
        printf("8. Mostrar el/los dueños con más autos estacionados.\n");
        printf("9. Salir.\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:

            break;

        case 9:
            printf("Chau");
            break;
        }
        system("pause");
        system("cls");
    }while(opcion != 9);
}
