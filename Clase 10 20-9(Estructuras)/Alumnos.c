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

    miAlumno.estado = LIBRE;

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

int cargarAlumnos(sAlumno lista[], int cant)
{
    int i;
    int retorno = 0;
    i = buscarLibre(lista, cant);

    if(i != -1)
    {
        lista[i] = pedirAlumno();
        lista[i].estado = OCUPADO;
        retorno = 1;
    }

    return retorno;

}

void mostrarListadoDeAlumnos(sAlumno lista[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            mostrarAlumno(lista[i]);
        }

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
    char nombre[3][50]= {"Juan", "Maria", "Jose",};
    int i;

    for(i=0; i<cant; i++)
    {
        lista[i].legajo=legajo[i];
        lista[i].nota=nota[i];
        strcpy(lista[i].nombre, nombre[i]);
    }
}

int inicializarAlumnos(sAlumno* lista, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && lista != NULL)
    {
        for(i=0; i<cant; i++)
        {
            lista[i].estado = LIBRE;
        }
        retorno = 0;
    }

    return retorno;

}

int buscarLibre(sAlumno lista[], int cant)
{
    int i;
    int index= -1; // Si devuelve -1 no hay lugar(le di valor ilogico).
    for(i=0; i<cant; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i; // Devuelve el indice.
            break;
        }
    }
    return index;
}

int buscarAlumnoPorLegajo(sAlumno* lista, int cant, int legajo)
{
    int i;
    int retorno = -1;

    if(lista!=NULL && cant > 0)
    {
        for(i=0; i<cant; i++)
        {

            if(lista[i].legajo == legajo)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int darBajaPorLegajo(sAlumno* lista,int cant)
{
    int retorno = -1;
    int legajo;
    int index;
    char respuesta;
    if(lista!=NULL && cant > 0)
    {
        mostrarListadoDeAlumnos(lista, cant);

        printf("Ingrese un legajo: ");
        scanf("%d", &legajo);

        index = buscarAlumnoPorLegajo(lista, cant, legajo);

        if(index != -1)
        {
            mostrarAlumno(lista[index]);
            printf("Presione s para eliminar al alumno.");
            respuesta = getche();
            if(respuesta == 's')
            {
                lista[index].estado=LIBRE;
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

int modificarAlumnoPorLegajo(sAlumno* lista, int cant)
{
    int retorno = -1;
    int legajo;
    int index;
    int opcion;

    mostrarListadoDeAlumnos(lista, cant);

    printf("Ingrese el legajo del alumno que desea modificar: ");
    scanf("%d", &legajo);

    index = buscarAlumnoPorLegajo(lista, cant, legajo);

    if(index != -1)
    {
        mostrarAlumno(lista[index]);
        printf("Que desea modificar?\n");
        printf("1.Nombre.\n");
        printf("2.Nota.\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(lista[index].nombre);
            retorno = 0;
            break;
        case 2:
            printf("Ingrese la nota: ");
            scanf("%d", &lista[index].nota);
            retorno = 0;
            break;
        default:
            printf("Opcion invalida.");
            retorno = 1;
            break;
        }

    }

    return retorno;

}
