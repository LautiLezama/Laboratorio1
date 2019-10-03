#include "propietario.h"
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

void hardcodeAutos(eVehiculo list[], int cant)
{
    int i;
    char patente[][10]= {"AAA111", "BBB222", "AAA222", "WWW777",
                        "AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int horaSalida[] = {11,11,11,12,14,15,12,10,11,17};

    for(i=0; i<cant; i++)
    {
        strcpy(list[i].patente,patente[i]);
        list[i].fechaIngreso.dia = dia;
        list[i].fechaIngreso.mes = mes;
        list[i].fechaIngreso.anio = anio;
        list[i].horaEntrada = horaIngreso[i];
        list[i].horaSalida = horaSalida[i];
    }

}

void hardcodePersonas(ePropietario list[],int cant)
{
    char nombre[][51]= {"Ezequiel","Ezequiel","German","Yanina"};
    int anio[]= {1990,1980,2000,1995};
    int mes[]= {3,4,12,11};
    int dia[]= {33,22,25,11};
    int id[]= {1,2,3,4};
    int i;

    for(i=0; i<cant; i++)
    {
        list[i].idPropietario=id[i];
        list[i].fechaNacimiento.anio = anio[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.dia = dia[i];
        strcpy(list[i].nombre, nombre[i]);
    }
}

void ordenarByNombreAndAnio(ePropietario list[], int cant)
{
    ePropietario auxPropietario;
    int i;
    int j;

    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(list[i].nombre, list[j].nombre) > 0)
            {
                auxPropietario = list[i];
                list[i] = list[j];
                list[j] = auxPropietario;
            }
        }
    }
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(list[i].nombre, list[j].nombre) == 0)
            {
                if(list[i].fechaNacimiento.anio > list[j].fechaNacimiento.anio)
                {
                    auxPropietario = list[i];
                    list[i] = list[j];
                    list[j] = auxPropietario;
                }

            }
        }
    }
}

void mostrarListadoPersonas(ePropietario list[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("%02d \t %20s \t %02d/%02d/%4d \n", list[i].idPropietario
               , list[i].nombre
               , list[i].fechaNacimiento.dia
               , list[i].fechaNacimiento.mes
               , list[i].fechaNacimiento.anio
              );
    }
}

void ordenarByDuenioAndPatente(eVehiculo listV[],ePropietario listP[], int cant)
{
    int i;
    int j;
    eVehiculo auxVehiculo;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(listP[i].nombre, listP[j].nombre) > 0)
            {
                auxVehiculo = listV[i];
                listV[i] = listV[j];
                listV[j] = auxVehiculo;
            }
        }
    }
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(listP[i].nombre, listP[j].nombre) == 0)
            {
                if(strcmp(listV[i].patente, listV[j].patente) < 0)
                {
                    auxVehiculo = listV[i];
                    listV[i] = listV[j];
                    listV[j] = auxVehiculo;
                }
            }
        }
    }
}

void mostrarListadoAutos(eVehiculo listV[],ePropietario listP[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("%02d \t %10s \t %02d,%02d,%4d \t %02d \t %02d \t %20s",listV[i].idPropietario
                                                                      ,listV[i].patente
                                                                      ,listV[i].fechaIngreso.dia
                                                                      ,listV[i].fechaIngreso.mes
                                                                      ,listV[i].fechaIngreso.anio
                                                                      ,listV[i].horaEntrada
                                                                      ,listV[i].horaSalida
                                                                      ,listP[i].nombre
                                                                      );
    }
}





