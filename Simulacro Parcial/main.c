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
        printf("1. Todas las personas ordenadas por nombre y a�o de nacimiento\n");
        printf("2. Todos los veh�culos ordenados por due�o y patente.\n");
        printf("3. Cada auto con el nombre de su due�o.\n");
        printf("4. Por cada due�o los autos que tiene estacionados.\n");
        printf("5. Ingresar un due�o y mostrar todos sus autos.\n");
        printf("6. Mostrar el total de la estad�a de cada auto, sabiendo que el valor hora es $100.\n");
        printf("7. Mostrar cuanto deber� pagar cada due�o por todos sus autos estacionados.\n");
        printf("8. Mostrar el/los due�os con m�s autos estacionados.\n");
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
