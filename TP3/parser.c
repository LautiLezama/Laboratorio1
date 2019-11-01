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
        employee_setId(listEmployees,atoi(id));
        employee_setHorasTrabajadas(listEmployees,atoi(horasTrabajadas));
        employee_setSueldo(listEmployees,atoi(sueldo));
        employee_setNombre(listEmployees,nombre);
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

    Employee* listEmployees;
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
        fread(id,sizeof(char),1,pFile);
        fread(nombre,sizeof(char),1,pFile);
        fread(horasTrabajadas,sizeof(char),1,pFile);
        fread(sueldo,sizeof(char),1,pFile);
        employee_setId(listEmployees,atoi(id));
        employee_setHorasTrabajadas(listEmployees,atoi(horasTrabajadas));
        employee_setSueldo(listEmployees,atoi(sueldo));
        employee_setNombre(listEmployees,nombre);
        ll_add(pArrayListEmployee, listEmployees);

    }
    while(!feof(pFile));

    return 1;
}
