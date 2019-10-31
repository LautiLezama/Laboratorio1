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
    Employee* empleadoA[2000];

    int i = 0;

    pArchivo = fopen("data.csv","r");

    parser_EmployeeFromText(pArchivo,listaEmpleados);

    for(i=0;i<ll_len(listaEmpleados);i++)
    {
       listaEmpleados = (Employee*)ll_get(empleadoA,i);

       printf("%d--%s--%d--%d", listaEmpleados,empleadoA[i]->nombre,empleadoA[i]->horasTrabajadas,empleadoA[i]->sueldo);
    }



    int option = 0;

    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/

    fclose(pArchivo);
    return 0;
}
