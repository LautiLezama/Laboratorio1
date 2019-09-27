#include "labibliopa.h"
#define P 4
#define V 10

int main()
{
    int i;
    int opcion;
    sPersona listaPersonas[P];
    sVehiculo listaAutitos[V];
    hardcodePersonas(listaPersonas, P);
    hardcodeoAutos(listaAutitos, V);

    do
    {
        printf("\n1.Mostrar los autos con el nombre de su dueño.\n");
        printf("2.Mostrar los dueños y sus autos estacionados.\n");
        printf("3.Ingresar un dueño y mostrar sus autos.\n");
        printf("4.Mostrar el total de la estadia de todos los autos. (1Hora = $100)\n");
        printf("5.Mostrar cuanto debe pagar cada dueño por todos sus autos.\n");
        printf("6.Mostrar los dueños con mas autos estacionados.\n");
        printf("7.Salir.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        printf("\n");

        switch(opcion)
        {
        case 1:
            mostrarAutitos(listaAutitos, listaPersonas, V);
            break;

        case 2:
            mostrarDueniosAndAutos(listaAutitos, listaPersonas, V);
            break;

        case 3:
            i = buscarPersonaById(listaPersonas, P);
            if(i!=-1)
            {
                mostrarAutosByDuenio(listaAutitos,listaPersonas,i,V);
            }
            else
            {
                printf("\nNo se encontro a la persona.\n");
            }
            break;

        case 4:
            cobrarPorAuto(listaAutitos,listaPersonas,V);
            break;

        default:
            printf("Opcion invalida.");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=7);

    return 0;
}

/*1.Cada auto con el nombre de su dueño
    2.Por cada dueño los autos que tiene estacionados.
    3.Ingresar un dueño y mostrar todos sus autos.
    4.Mostrar el total de la estadia de cada auto, sabiendo que
      el valor hora es $100
    5.Mostrar cuanto debera pagar cada dueño por todos sus autos estacionados
    6.Mostrar el/los dueños con mas autos estacionados */

