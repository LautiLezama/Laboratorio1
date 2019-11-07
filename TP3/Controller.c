#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"r");
    parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    fclose(pArchivo);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"rb");
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    fclose(pArchivo);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    int largo;
    int contId;
    int id;
    oneEmployee = employee_new();

    largo = ll_len(pArrayListEmployee);
    oneEmployee = (Employee*)ll_get(pArrayListEmployee, largo);
    contId = employee_getId(oneEmployee,id);
    incrementarId(&contId);
    employee_getId(oneEmployee,id);

    printf("Ingrese el nombre del empleado : ");
    fflush(stdin);
    gets(nombre);
    employee_getNombre(oneEmployee,nombre);

    printf("Ingrese las horas trabajadas del empleado : ");
    scanf("%d",&horasTrabajadas);
    employee_getHorasTrabajadas(oneEmployee,horasTrabajadas);

    printf("Ingrese el sueldo del empleado : ");
    scanf("%d",&sueldo);
    employee_getSueldo(oneEmployee,sueldo);

    ll_add(pArrayListEmployee, oneEmployee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

