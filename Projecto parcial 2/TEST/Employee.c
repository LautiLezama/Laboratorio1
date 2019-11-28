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


Employee* employee_newParametros(char* idLlamadaStr,char* fechaStr,char* numeroClienteStr,char* idProblemaStr,char* solucionadoStr)
{
    Employee* oneEmployee = employee_new();
    if(oneEmployee!=NULL)
    {
        setIdLlamada(oneEmployee,atoi(idLlamadaStr));
        setNumeroCliente(oneEmployee,atoi(numeroClienteStr));
        setIdProblema(oneEmployee,atoi(idProblemaStr));
        setFecha(oneEmployee,fechaStr);
        setSolucionado(oneEmployee,solucionadoStr);

    }
    return oneEmployee;
}


int setIdLlamada(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idLlamada=int1;
        r = 0;
    }
    return r;
}

int setNumeroCliente(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->numeroCliente=int1;
        r = 0;
    }
    return r;
}

int setIdProblema(Employee* this,int int1)
{
    int r = -1;
    if(this != NULL && int1>0)
    {
        this->idProblema=int1;
        r = 0;
    }
    return r;
}

int setFecha(Employee* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->fecha,char1);
        r = 0;
    }
    return r;
}

int setSolucionado(Employee* this,char* char1)
{
    int r = -1;
    if(this != NULL && char1>0)
    {
        strcpy(this->solucionado,char1);
        r = 0;
    }
    return r;
}

int getIdLlamada(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idLlamada;
    }
    return *int1;
}

int getNumeroCliente(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->numeroCliente;
    }
    return *int1;
}

int getIdProblema(Employee* this,int* int1)
{
    if(this != NULL)
    {
        *int1 = this->idProblema;
    }
    return *int1;
}

int getFecha(Employee* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->fecha);
    }
    return char1;
}

int getSolucionado(Employee* this,char* char1)
{
    if(this != NULL)
    {
        strcpy(char1, this->solucionado);
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
    int idLlamada;
    char fecha[50];
    int numeroCliente;
    int idProblema;
    char idProblemaText[50];
    char solucionado[5];


    aux = (Employee*)ll_get(pArrayListEmployee, index);
    getIdLlamada(aux, &idLlamada);
    getFecha(aux,&fecha);
    getNumeroCliente(aux,&numeroCliente);
    getIdProblema(aux, &idProblema);
    getSolucionado(aux,&solucionado);

    switch(idProblema)
    {
    case 1:
        strcpy(idProblemaText,"No enciende PC");
        break;
    case 2:
        strcpy(idProblemaText,"No funciona mouse");
        break;
    case 3:
        strcpy(idProblemaText,"No funciona teclado ");
        break;
    case 4:
        strcpy(idProblemaText,"No hay internet");
        break;
    case 5:
        strcpy(idProblemaText,"No funciona teléfono");
        break;
    }
    printf("%d--%s--%d--%s--%s\n",idLlamada,fecha,numeroCliente,idProblemaText,solucionado);
}

/////////////
/////////////
///////////// FILTRADOS
/////////////
/////////////

int filtrarProblema1(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->idProblema == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarProblema2(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->idProblema == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarProblema3(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->idProblema == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarProblema4(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->idProblema == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int filtrarProblema5(void* p1)
{
    Employee* oneEmployee = (Employee*)p1;
    if(oneEmployee->idProblema == 5)
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


/*int comparaPorNombre(void* p1, void* p2)
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
}*/
