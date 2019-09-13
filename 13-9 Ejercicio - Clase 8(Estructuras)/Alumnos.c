#include "Alumnos.h"

void mostrarAlumno(sAlumno unAlumno)
{
    printf("%d %s %d\n", unAlumno.legajo, unAlumno.nombre, unAlumno.nota);
}

sAlumno pedirAlumno()
{
    sAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);

    printf("Ingrese nota: ");
    scanf("%d", &miAlumno.nota);

    return miAlumno;
}

int compararAlumnoByLegajo(sAlumno alumno1, sAlumno alumno2)
{
    int comp = 0;

    if(alumno1.legajo == alumno2.legajo)
    {
        comp = 1;
    }

    return comp;
}

void cargarAlumnos(sAlumno lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        lista[i]=pedirAlumno();
    }
}

void mostrarListadoDeAlumnos(sAlumno lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarAlumno(lista[i]);
    }
}

void ordenarAlumnosByNombre(sAlumno lista[], int cantidad)
{
    int i;
    int j;
    sAlumno auxAlumno;

    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) < 0)
            {
                auxAlumno = lista[i];
                lista[i] = lista[j];
                lista[j] = auxAlumno;
            }


        }

    }

}

void hardcodearAlumnos(sAlumno lista[], int cant)
{

    int legajo[3]= {101,102,105};
    int nota[3]= {10,5,9};
    char nombre[3][50]={"Juan", "Maria", "Jose",};
    int i;

    for(i=0; i<cant; i++)
    {
       lista[i].legajo=legajo[i];
       lista[i].nota=nota[i];
       strcpy(lista[i].nombre, nombre[i]);
    }
}
