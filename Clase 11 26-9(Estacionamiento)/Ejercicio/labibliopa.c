#include "labibliopa.h"

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
        listaPersonas[i].idPersona =id[i];
        listaPersonas[i].fechaNac.anio = anio[i];
        listaPersonas[i].fechaNac.mes = mes[i];
        listaPersonas[i].fechaNac.dia = dia[i];
        strcpy(listaPersonas[i].nombre, nombre[i]);
    }
}

void hardcodeoAutos(sVehiculo listaAutitos[], int cant)
{
    int i;
    char patente[][10]= {"AAA111", "BBB222", "AAA222", "WWW777",
                        "AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int horaSalida[] = {11,11,11,12,14,15,12,10,11,17};
    int idAuto[]={101,106,100,106,101,101,100,105,106,106};

    for(i=0; i<cant; i++)
    {
        strcpy(listaAutitos[i].patente,patente[i]);
        listaAutitos[i].fechaIngreso.dia = dia;
        listaAutitos[i].fechaIngreso.mes = mes;
        listaAutitos[i].fechaIngreso.anio = anio;
        listaAutitos[i].horaIngreso = horaIngreso[i];
        listaAutitos[i].horaSalida = horaSalida[i];
        listaAutitos[i].idAuto = idAuto[i];
    }

}

void mostrarPersonas(sPersona listaPersonas[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarUnaPersona(listaPersonas[i]);
    }
}



void mostrarAutitos(sVehiculo listaAutitos[],sPersona lista[], int cant)
{

    int i;
    printf("  Patente \t Hora Ingreso \t Hora Salida \t Fecha Ingreso \n");
    for(i=0; i<cant; i++)
    {
        mostrarUnAutito(listaAutitos[i],lista,cant);
    }
}

int buscarPorPatente(sVehiculo listaAutitos[],int cant)
{
    int i;
    char patente[51];
    printf("\nIngresa la patente master : ");
    fflush(stdin);
    gets(patente);
    for(i=0; i<cant; i++)
    {
        if(strcmp(listaAutitos[i].patente, patente) == 0)
        {
            return i;
        }
    }
    return -1;
}

void mostrarUnAutito(sVehiculo unAutito, sPersona lista[],int cant)
{
    int i;
    printf("%8s \t %02d \t\t %02d \t\t %02d/%02d/%4d \t",unAutito.patente
                                         ,unAutito.horaIngreso
                                         ,unAutito.horaSalida
                                         ,unAutito.fechaIngreso.dia
                                         ,unAutito.fechaIngreso.mes
                                         ,unAutito.fechaIngreso.anio);

    for(i=0; i<cant; i++)
    {
        if(unAutito.idAuto == lista[i].idPersona)
        {
            printf("Duenio: %s\n\n", lista[i].nombre);
            break;
        }
    }

}

void mostrarUnaPersona(sPersona unaPersona)
{
     printf("%02d %20s \t %02d/%02d/%4d \n", unaPersona.idPersona
               , unaPersona.nombre
               , unaPersona.fechaNac.dia
               , unaPersona.fechaNac.mes
               , unaPersona.fechaNac.anio);
}

int buscarPersonaById(sPersona lista[], int cant)
{
    int i;
    int id;

    mostrarPersonas(lista,cant);

    printf("\nIngrese el ID del duenio : ");
    scanf("%d", &id);
    printf("\n");

    for(i=0;i<cant;i++)
    {
        if(id == lista[i].idPersona)
        {
            return id;
        }
    }
    return -1;
}

void mostrarAutosByDuenio(sVehiculo listV[],sPersona listP[],int id,int cant)
{
 int i;
 for(i=0;i<cant;i++)
 {
     if(id == listV[i].idAuto)
     {
         mostrarUnAutito(listV[i],listP,cant);
     }
 }
}

void mostrarDueniosAndAutos(sVehiculo listV[], sPersona listP[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        mostrarAutosByDuenio(listV,listP,listP[i].idPersona,cant);
    }
}

void cobrarPorAuto(sVehiculo listV[],sPersona listP[], int cant)
{
    int i;
    mostrarAutitos(listV,listP, cant);
    i = buscarPorPatente(listV, cant);
    int laPlata;
    laPlata = listV[i].horaSalida - listV[i].horaIngreso;
    laPlata = laPlata * 100;
    printf("El total por su estadia es %d \n", laPlata);
}

void cobrarPorDuenio(sVehiculo listV[], sPersona listP[], int cant)
{

}




