#include "Employee.h"
#include <malloc.h>


Employee* employee_new()
{
    return (Employee*)(malloc(sizeof(Employee)));
}

/////////////
/////////////
/////////////   PARAMETROS, SETTERS Y GETTERS.
/////////////
/////////////


Employee* employee_newParametros(char* intStr,char* charStr)
{
    Employee* oneEmployee = employee_new();
    if(oneEmployee!=NULL)
    {
        setInt(oneEmployee,atoi(intStr));
        setChar(oneEmployee,charStr);
    }
    return oneEmployee;
}


int setInt(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->CAMBIAR=int1;
        r = 0;
    }
    return r;
}

int setChar(Employee* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->CAMBIAR,char1);
        r = 0;
    }
    return r;
}

int getInt(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->CAMBIAR;
    }
    return *int1;
}

int sGetChar(Employee* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->CAMBIAR);
    }
    return char1;
}

/////////////
/////////////
///////////// LISTADO
/////////////
/////////////

void employee_showOneEmployee(LinkedList* pArrayListEmployee,int index)
{
    Employee* aux;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];

    aux = (Employee*)ll_get(pArrayListEmployee, index);
    employee_getId(aux, &id);
    employee_getNombre(aux,&nombre);
    employee_getSueldo(aux,&sueldo);
    employee_getHorasTrabajadas(aux, &horasTrabajadas);
    printf("%d--%s--%d--%d\n",id,nombre,sueldo,horasTrabajadas);
}

/////////////
/////////////
///////////// FILTRADOS
/////////////
/////////////

int filtrarPorSueldo(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->sueldo == 12000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/////////////
/////////////
/////////////
/////////////
/////////////


int comparaPorNombre(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return strcmp(empleado1->nombre,empleado2->nombre);

}

int comparaPorSueldos(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return intCmp(empleado1->sueldo,empleado2->sueldo);

}

int comparaPorHorasTrabajadas(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return intCmp(empleado1->horasTrabajadas,empleado2->horasTrabajadas);
}



void employee_showOneEmployee(LinkedList* pArrayListEmployee,int index)
{
    Employee* aux;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];

    aux = (Employee*)ll_get(pArrayListEmployee, index);
    employee_getId(aux, &id);
    employee_getNombre(aux,&nombre);
    employee_getSueldo(aux,&sueldo);
    employee_getHorasTrabajadas(aux, &horasTrabajadas);
    printf("%d--%s--%d--%d\n",id,nombre,sueldo,horasTrabajadas);
}

int filtrarPorSueldo(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->sueldo == 12000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_findById(Employee* listEmployees,LinkedList* pArrayListEmployee)
{
    int i;
    int idEmployee;
    int id;
    int r = -1;
    printf("Ingrese el ID del empleado : ");
    scanf("%d",&id);

    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
       listEmployees = ll_get(pArrayListEmployee,i);
       employee_getId(listEmployees,&idEmployee);
       if(idEmployee==id)
       {
           return i;
       }
    }
    return r;
}
