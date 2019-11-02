#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char mail[50];
    float sueldo;

}eEmpleado;

int main()
{
    FILE* pArchivo;
    eEmpleado listEmpleados[50];
    eEmpleado unEmpleado;
    char id[50];
    char nombre[50];
    char apellido[50];
    char mail[50];
    char sueldo[50];
    int i=0;

    pArchivo = fopen("empleados.csv","r");
    fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,mail,sueldo);

    while(!feof(pArchivo))
    {
        fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,mail,sueldo);//%[^,], La , de adentro significa que va hasta la coma, la de afuera significa que no la incluye.
        unEmpleado.id = atoi(id); //parseInt
        strcpy(unEmpleado.nombre,nombre);
        strcpy(unEmpleado.apellido,apellido);
        strcpy(unEmpleado.mail,mail);
        unEmpleado.sueldo = atof(sueldo); //parseFloat
        listEmpleados[i]=unEmpleado;
        i++;
    }

    fclose(pArchivo);

    for(i=0;i<50;i++)
    {
        printf("%d--%s--%s--%s--%f \n",listEmpleados[i].id,listEmpleados[i].nombre,listEmpleados[i].apellido,listEmpleados[i].mail,listEmpleados[i].sueldo);
    }


    return 0;
}

//Ejemplos archivos en c github scarafilo.
//german2017
