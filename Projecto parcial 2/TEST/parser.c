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
    int r = 0;
    char idLlamada[50];
    char fecha[50];
    char numeroCliente[50];
    char idProblema[50];
    char solucionado[50];
    if(pFile == NULL)
    {
        return -1;
    }
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLlamada,fecha,numeroCliente,idProblema,solucionado);
    do
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLlamada,fecha,numeroCliente,idProblema,solucionado);
        listEmployees = employee_newParametros(idLlamada,fecha,numeroCliente,idProblema,solucionado);
        ll_add(pArrayListEmployee, listEmployees);

    }
    while(!feof(pFile));

    return r;
}





/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* listEmployees;
    if(pFile == NULL)
    {
        return -1;
    }
    while(!feof(pFile))
    {
        listEmployees = employee_new();
        fread(listEmployees,sizeof(Employee),1,pFile);
        if(feof(pFile))
        {
            break;
        }
        ll_add(pArrayListEmployee, listEmployees);
    }

    return 1;
}*/
