#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* listEmployees;
    int i = 0;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    if(pFile == NULL)
    {
        return -1;
    }
    do
    {
        listEmployees = employee_new();
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        listEmployees->id = atoi(id);
        listEmployees->horasTrabajadas = atoi(horasTrabajadas);
        strcpy(listEmployees->nombre,nombre);
        listEmployees->sueldo = atoi(sueldo);
        ll_add(pArrayListEmployee, listEmployees);

    }
    while(!feof(pFile));

    return 1;
}





/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
