#include "Employee.h"

Employee* employee_new()
{
    return (Employee*)(malloc(sizeof(Employee)));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* oneEmployee = employee_new();
    if(oneEmployee!=NULL)
    {
        oneEmployee->id = atoi(idStr);
        strcpy(oneEmployee->nombre,nombreStr);
        oneEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
    }
    return oneEmployee;
}

int employee_setId(Employee* this,int id)
{
    int r = -1;
    if(this != NULL && id>0)
    {
        this->id=id;
        r = 0;
    }
    return r;
}

int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        id = this->id;
    }
    return id;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r = -1;
    if(this != NULL && nombre>0)
    {
        strcpy(this->nombre,nombre);
        r = 0;
    }
    return r;
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
    }
    return nombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r = -1;
    if(this != NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        r = 0;
    }
    return r;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this != NULL)
    {
        horasTrabajadas = this->horasTrabajadas;
    }
    return horasTrabajadas;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r = -1;
    if(this != NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        r = 0;
    }
    return r;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL)
    {
        sueldo = this->sueldo;
    }
    return sueldo;
}

int comparaPorNombre(void* p1, void* p2)
{
    Employee* empleado1 = (Employee*)p1;
    Employee* empleado2 = (Employee*)p2;
    return strcmp(empleado1->nombre,empleado2->nombre);

}

void incrementarId(int* ultimoId)
{
    *ultimoId = *ultimoId + 1;
}
