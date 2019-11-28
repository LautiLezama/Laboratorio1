#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>
typedef struct
{
    int idLlamada;
    char fecha[50];
    int numeroCliente;
    int idProblema;
    char solucionado[50];
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char*,char*,char*,char*,char*);
void employee_delete();

int setIdLlamada(Employee* this,int int1);
int setNumeroCliente(Employee* this,int int1);
int setIdProblema(Employee* this,int int1);
int setFecha(Employee* this,char* char1);
int setSolucionado(Employee* this,char* char1);

int getIdLlamada(Employee* this,int* int1);
int getNumeroCliente(Employee* this,int* int1);
int getIdProblema(Employee* this,int* int1);
int getFecha(Employee* this,char* char1);
int getSolucionado(Employee* this,char* char1);

int filtrarProblema1(void*);
int filtrarProblema2(void*);
int filtrarProblema3(void*);
int filtrarProblema4(void*);
int filtrarProblema5(void*);


int comparaPorNombre(void* , void* );
int comparaPorSueldos(void*,void*);
int comparaPorHorasTrabajadas(void*,void*);
int employee_findById(Employee*,LinkedList*);
void employee_showOneEmployee(LinkedList*,int);
int filtrarPorSueldo(void*);

#endif // employee_H_INCLUDED
