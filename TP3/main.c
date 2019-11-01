#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    FILE* pArchivo;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* Empleado;
    Employee* aux;
    int* punteroInt;
    char* punteroNombres[51];
    int option = 0;
    int i = 0;
    pArchivo = fopen("data.csv","r");


   /** Empleado = employee_new();
    Empleado = employee_newParametros("100","Maria","10");
    employee_setSueldo(Empleado,1000);
    ll_add(listaEmpleados,Empleado);

    for(i=0; i<ll_len(listaEmpleados); i++)
    {
        aux = (Employee*)ll_get(listaEmpleados, i);
        printf("%d--%s--%d--%d \n",employee_getId(aux,punteroInt),employee_getNombre(aux,punteroNombres),employee_getHorasTrabajadas(aux,punteroInt),employee_getSueldo(aux, punteroInt));
    }

    ll_sort(listaEmpleados,comparaPorNombre,1);

    printf("\nListado ordenado \n");

    for(i=0; i<ll_len(listaEmpleados); i++)
    {
        aux = (Employee*)ll_get(listaEmpleados, i);
        printf("%d--%s--%d--%d \n",employee_getId(aux,punteroInt),employee_getNombre(aux,punteroNombres),employee_getHorasTrabajadas(aux,punteroInt),employee_getSueldo(aux, punteroInt));
    } **/











    do
    {
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado.\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleados.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir.\n");
        printf("Elija una opcion : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
    }
    while(option != 10);

    fclose(pArchivo);
    return 0;
}
