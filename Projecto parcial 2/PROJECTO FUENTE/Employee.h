#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char*,char*,char*);
void employee_delete();

int setId(Employee* this,int int1);
int sGetChar(Employee* this,char* char1);

int getId(Employee* this,int* int1);
int sGetChar(Employee* this,char* char1);

int filtrado(Employee* this, int)


int comparaPorNombre(void* , void* );
int comparaPorSueldos(void*,void*);
int comparaPorHorasTrabajadas(void*,void*);
int employee_findById(Employee*,LinkedList*);
void employee_showOneEmployee(LinkedList*,int);
int filtrarPorSueldo(void*);

#endif // employee_H_INCLUDED
