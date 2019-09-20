#include "Alumnos.h"
#define A 3


int main()
{
    sAlumno listaAlumno[A];
    if(inicializarAlumnos(listaAlumno, A)==0)
    {

        int opcion;
        int index;
        int retorno;


        do
        {
            printf("1. Cargar alumnos \n");
            printf("2. Mostrar alumnos \n");
            printf("3. Ordenar alumnos por nombre \n");
            printf("4. Buscar alumno por legajo.\n");
            printf("5. Dar baja por legajo.\n");
            printf("6. Salir.\n");
            printf("Elija una opcion : ");
            scanf("%d", &opcion);

            switch(opcion)
            {

            case 1:

                if(cargarAlumnos(listaAlumno, A)==1)
                {
                    printf("Alumno cargado con exito.\n");
                }
                else
                {
                    printf("No hay espacio.\n");
                }
                break;

            case 2:

                mostrarListadoDeAlumnos(listaAlumno, A);
                break;

            case 3:

                ordenarAlumnosByNombre(listaAlumno, A);
                break;

            case 4:

                index=buscarAlumnoPorLegajo(listaAlumno,A,100);
                mostrarAlumno(listaAlumno[index]);
                break;

            case 5:
                retorno = darBajaPorLegajo(listaAlumno,A);
                switch(retorno)
                {
                case 0:
                    printf("Se elimino el alumno.\n");
                    break;

                case 1:
                    printf("Accion cancelada.\n");

                case -1:
                    printf("No se encontro el legajo.\n");

                }
                break;

            }
            system("pause");
            system("cls");
        }
        while(opcion!=6);

    }
    else
    {
        printf("Hubo un error MASTER CRACK");
    }







    return 0;
}



