#include "asd.h"


/*ePropietario pedirPropietario()
{
    ePropietario unPropietario;

    printf("Ingrese el nombre del propietario: ");
    fflush(stdin);
    gets(unPropietario.nombre);

    printf("\nIngrese la fecha de nacimiento: ");
    scanf("%d", &unPropietario.fechaNacimiento.dia);
    printf("/");
    scanf("%d", &unPropietario.fechaNacimiento.mes);
    printf("/");
    scanf("%d", &unPropietario.fechaNacimiento.anio);

}*/

void hardcodePersonas(ePropietario list[],int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","German","Yanina"};
    int anio[]= {1990,1980,2000,1995};
    int mes[]= {3,4,12,11};
    int dia[]= {33,22,25,11};
    int id[]={1,2,3,4};
    int i;

    for(i=0; i<cant; i++)
    {
        list[i].idPersona =id[i];
        list[i].fechaNacimiento.anio = anio[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.dia = dia[i];
        strcpy(list[i].nombre, nombre[i]);
    }
}
