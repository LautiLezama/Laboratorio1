#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <conio.h>
#include "parser.h"
#include "Validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r;
    FILE* pArchivo;
    pArchivo = fopen(path,"r");
    r = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    fclose(pArchivo);

    return r;
}

/*int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(path,"rb");
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    fclose(pArchivo);
    return 1;
}*/


/*int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    Employee* aux;
    int r;
    char nombre[50];
    int sueldo;
    int horasTrabajadas;
    int largo;
    int id;
    oneEmployee = employee_new();

    largo = ll_len(pArrayListEmployee);
    aux = (Employee*)ll_get(pArrayListEmployee, largo-1);
    employee_getId(aux,&id);
    employee_setId(oneEmployee, id+1);


    printf("Ingrese el nombre del empleado : ");
    enterString(nombre);
    r = soloLetras(nombre);
    while(r==-1)
    {
        printf("Solo se permiten letras. Reingrese el nombre del empleado : ");
        enterString(nombre);
        r = soloLetras(nombre);
    }
    employee_setNombre(oneEmployee,nombre);

    horasTrabajadas = enterInt("Ingrese las horas trabajadas del empleado : ");
    r = soloPositivos(horasTrabajadas);
    while(r==-1)
    {
        horasTrabajadas = enterInt("No puede tener horas trabajadas en negativo. Reingrese las horas trabajadas del empleado : ");
        r = soloPositivos(horasTrabajadas);
    }

    employee_setHorasTrabajadas(oneEmployee,horasTrabajadas);

    sueldo = enterInt("Ingrese el sueldo del empleado : ");
    r = soloPositivos(sueldo);
    while(r==-1)
    {
        sueldo = enterInt("No puede tener sueldo negativo. Reingrese el sueldo del empleado : ");
        r = soloPositivos(sueldo);
    }
    employee_setSueldo(oneEmployee,sueldo);

    ll_add(pArrayListEmployee, oneEmployee);
    return 1;
}*/


/*int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    Employee* oneEmployee;
    char nombre[50];
    int r = -1;
    int index;
    int horasTrabajadas;
    int sueldo;
    index = employee_findById(oneEmployee,pArrayListEmployee);
    if(index!=-1)
    {
        employee_showOneEmployee(pArrayListEmployee,index);
        oneEmployee = (Employee*)ll_get(pArrayListEmployee, index);
        printf("Que desea modificar.\n");
        printf("1.Nombre.\n");
        printf("2.Horas trabajadas.\n");
        printf("3.Sueldo.\n");
        printf("Ingrese una opcion : ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese el nuevo nombre : ");
            enterString(nombre);
            r = soloLetras(nombre);
            while(r==-1)
            {
                printf("Solo se permiten letras. Reingrese el nombre : ");
                enterString(nombre);
                r = soloLetras(nombre);
            }
            employee_setNombre(oneEmployee,nombre);
            r = 0;
            break;
        case 2:
            horasTrabajadas = enterInt("Ingrese las nuevas horas trabajadas del empleado : ");
            r = soloPositivos(horasTrabajadas);
            while(r==-1)
            {
                horasTrabajadas = enterInt("No puede tener horas trabajadas en negativo. Reingrese las horas trabajadas : ");
                r = soloPositivos(horasTrabajadas);
            }
            employee_setHorasTrabajadas(oneEmployee,horasTrabajadas);
            r = 0;
            break;
        case 3:
            sueldo = enterInt("Ingrese el nuevo sueldo del empleado : ");
            r = soloPositivos(sueldo);
            while(r==-1)
            {
                sueldo = enterInt("No puede tener el sueldo en negativo. Reingrese el sueldo del empleado : ");
                r = soloPositivos(sueldo);
            }
            employee_setSueldo(oneEmployee,sueldo);
            r = 0;
            break;
        default:
            r = 1;
            break;
        }
    }


    return r;
}*/


/*int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    int r = -1;
    int index;
    char respuesta;
    index = employee_findById(oneEmployee,pArrayListEmployee);
    if(index!=-1)
    {
        employee_showOneEmployee(pArrayListEmployee,index);
        oneEmployee = (Employee*)ll_get(pArrayListEmployee, index);
        printf("Esta seguro que desea eliminar a este empleado? Presione s para confirmar : ");
        respuesta = getche();
        if(respuesta!='s')
        {
            return 1;
        }
        ll_remove(pArrayListEmployee,index);
        r = 0;
    }
    return r;
}*/


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        showUnVuelo(pArrayListEmployee,i);
    }
    return 1;
}


/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int r = 0;
    printf("\n\n�Bajo que criterio quiere ordenar?\n");
    printf("1.Nombres\n");
    printf("2.Sueldos\n");
    printf("3.Horas trabajadas\n");
    printf("\nElija una opcion : ");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        printf("Orden ascendente o descendente?\n");
        printf("1.Ascendente.\n");
        printf("2.Descendente.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        if(opcion == 1)
        {
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorNombre,1);
        }
        else if(opcion == 2)
        {
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorNombre,0);
        }
        else
        {
            return 1;
        }
        break;
    case 2:
        printf("Orden ascendente o descendente?\n");
        printf("1.Ascendente.\n");
        printf("2.Descendente.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        if(opcion == 1)
        {
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorSueldos,1);

        }
        else if(opcion == 2)
        {
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorSueldos,0);

        }
        else
        {
            return 1;
        }

        break;
    case 3:
        printf("Orden ascendente o descendente?\n");
        printf("1.Ascendente.\n");
        printf("2.Descendente.\n");
        printf("\nElija una opcion : ");
        scanf("%d",&opcion);
        if(opcion == 1)
        {
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorHorasTrabajadas,1);

        }
        else if(opcion == 2)
        {
            printf("\n\nAguarde un momento por favor...");
            ll_sort(pArrayListEmployee,comparaPorHorasTrabajadas,0);

        }
        else
        {
            return 1;
        }
        break;
    default:
        r = 1;
        break;
    }

    return r;
}*/


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    sVuelo* listEmployees;
    int r = 0;
    int i;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    pFile = fopen(path, "w");
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        listEmployees = (sVuelo*)ll_get(pArrayListEmployee,i);
        getIdVuelo(listEmployees, &idVuelo);
    getIdAvion(listEmployees,&idAvion);
    getIdPiloto(listEmployees,&idPiloto);
    getFecha(listEmployees, &fecha);
    getDestino(listEmployees, &destino);
    getCantPasajeros(listEmployees,&cantPasajeros);
    getHoraDespegue(listEmployees,&horaDespegue);
    getHoraLlegada(listEmployees, &horaLlegada);
        fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
    }

    fclose(pFile);
    return r;

}


/*int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* listEmployees;
    int r = 0;
    int i;
    pFile = fopen(path, "wb");
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {

        listEmployees = (Employee*)ll_get(pArrayListEmployee,i);
        //employee_showOneEmployee(pArrayListEmployee, i);
        fwrite(listEmployees,sizeof(Employee),1,pFile);
    }

    fclose(pFile);
    return r;
}*/

int controller_filtrarVuelosCortos(LinkedList* pArrayListEmployee)
{

    int r=-1;
    LinkedList* listaFiltrada = NULL;
    listaFiltrada = ll_filter(pArrayListEmployee,filtrarVuelosCortos);

    if(listaFiltrada != NULL)
    {
        r=0;
        if(ll_len(listaFiltrada)>0)
        {
            //controller_ListEmployee(listaFiltrada);
        controller_saveAsText("listaFiltrada.csv", listaFiltrada);
        }
        else
        {
            printf("\n\n Ningun vuelo cumple esa condicion. \n\n");
        }
    }
    return r;
}

int controller_listarVuelosPortugal(LinkedList* pArrayListEmployee)
{
    int r=-1;
    LinkedList* listaFiltrada = NULL;
    listaFiltrada = ll_filter(pArrayListEmployee,filtrarVuelosPortugal);

    if(listaFiltrada != NULL)
    {
        r=0;
        if(ll_len(listaFiltrada)>0)
        {
        controller_ListEmployee(listaFiltrada);
        }
        else
        {
        printf("\n\n Ningun vuelo cumple esa condicion. \n\n");
        }
    }
    return r;
}

int controller_filtrarAlexLifeson(LinkedList* pArrayListEmployee)
{
    int r=-1;
    LinkedList* listaFiltrada = NULL;
    listaFiltrada = ll_filter(pArrayListEmployee,filtrarAlexLifeson);

    if(listaFiltrada != NULL)
    {
        r=0;
        if(ll_len(listaFiltrada)>0)
        {
        controller_ListEmployee(listaFiltrada);
        }
        else
        {
        printf("\n\n Ningun vuelo cumple esa condicion. \n\n");
        }
    }
    return r;
}


int controller_pasajerosTotales(LinkedList* pArrayListEmployee)
{
    return ll_count(pArrayListEmployee,contadorPasajerosTotal);
}

int controller_pasajerosIrlanda(LinkedList* pArrayListEmployee)
{
    return ll_count(pArrayListEmployee,contadorPasajerosIrlanda);
}


