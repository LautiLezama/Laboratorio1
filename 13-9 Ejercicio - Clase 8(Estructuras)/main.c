#include "Alumnos.h"
#define A 3


int main()
{

    sAlumno listaAlumno[A];// ={1000,"Pepe",7};
    int opcion;

    do
    {
        printf("1. Cargar alumnos \n");
        printf("2. Mostrar alumnos \n");
        printf("3. Ordenar alumnos por nombre \n");
        printf("Elija una opcion : ");
        scanf("%d", &opcion);

        switch(opcion)
        {

    case 1:

        //cargarAlumnos(listaAlumno, A);
        hardcodearAlumnos(listaAlumno, A);
        break;

    case 2:

        mostrarListadoDeAlumnos(listaAlumno, A);
        break;

    case 3:

        ordenarAlumnosByNombre(listaAlumno, A);
        break;

        }
    system("pause");
    system("cls");
    }while(opcion!=5);






    return 0;
}

