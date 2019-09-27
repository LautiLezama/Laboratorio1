#include "biblio.h"

void hardcodeoAutos(sVehiculo listaAutitos[], int cant)
{
    int i;
    char patente[][8]= {"AAA111", "BBB222", "AAA222", "WWW777",
                        "AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int horaSalida[] = {11,11,11,12,14,15,12,10,11,17};
    int idPersona[]={101,106,100,106,101,101,100,105,106,106};

    for(i=0; i<cant; i++)
    {
        strcpy(listaAutitos[i].patente,patente[i]);
        listaAutitos[i].fechaIngreso.dia = dia;
        listaAutitos[i].fechaIngreso.mes = mes;
        listaAutitos[i].fechaIngreso.anio = anio;
        listaAutitos[i].horaIngreso = horaIngreso[i];
        listaAutitos[i].horaSalida = horaSalida[i];
        listaAutitos[i].idDuenio = idPersona[i];
    }
}

void hardcodePersonas(sPersona listaPersonas[],int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","German","Yanina"};
    int anio[]= {1990,1980,2000,1995};
    int mes[]= {3,4,12,11};
    int dia[]= {33,22,25,11};
    int id[]={100,101,105,106};
    int i;

    for(i=0; i<cant; i++)
    {
        listaPersonas[i].id =id[i];
        listaPersonas[i].fechaNac.anio = anio[i];
        listaPersonas[i].fechaNac.mes = mes[i];
        listaPersonas[i].fechaNac.dia = dia[i];
        strcpy(listaPersonas[i].nombre, nombre[i]);
    }
}
