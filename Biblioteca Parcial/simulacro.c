#include "simulacro.h"

int onlyNumbers(int num1)
{
    char snum[100];
    int i;
    int largo;
    int r = 0;
    itoa(num1, snum, 100);
    largo = strlen(snum);

    for(i=0;i<largo;i++)
    {
        if(snum[i] < 48 || snum[i] > 57)
        {
            r = -2;
            return r;
        }
    }
    return r;
}

int onlyLetters(char string1[])
{
    int i;
    int largo;
    int r = 0;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(((string1[i]<97 && string1[i]>90) || string1[i]>122) || string1[i]<65)
        {
            r = -2;
            return r;
        }
    }
    return r;
}

int enterInt(int num1)
{
    scanf("%d", &num1);
    return num1;
}

float enterFloat(float num1)
{
    scanf("%f", &num1);
    return num1;
}

char* enterString(char* string1)
{
    fflush(stdin);
    gets(string1);
    return string1;
}

int inicializarPropietarios(sPropietario list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

int inicializarVehiculos(sVehiculo list[], int cant)
{
    int i;
    int r=-1;
    if(cant > 0 && list != NULL)
    {
        r = 0;
        for(i=0; i<cant; i++)
        {
            list[i].estado = LIBRE;
        }
    }
    return r;
}

void hardcodeoPropietarios(sPropietario list[], int cant)
{
    char nombre[][51]= {"Maria","Ezequiel","Gonzalo","Ezequiel"};
    int dia[]= {20,05,31,15};
    int mes[]= {02,05,03,12};
    int anio[]= {2000,2001,1965,1996};
    int id[]= {1,2,3,4};
    int i;
    for(i=0; i<cant; i++)
    {
        list[i].idPropietario = id[i];
        strcpy(list[i].nombre,nombre[i]);
        list[i].fechaNacimiento.dia = dia[i];
        list[i].fechaNacimiento.mes = mes[i];
        list[i].fechaNacimiento.anio = anio[i];
        list[i].estado = OCUPADO;
    }
}



sPropietario pedirPropietario()
{

    sPropietario unPropietario;

    printf("Ingrese el nombre del propietario : ");
    enterString(unPropietario.nombre);

    printf("Ingrese la fecha de nacimiento\n");
    printf("Dia : ");
    scanf("%d", &unPropietario.fechaNacimiento.dia);
    printf("Mes : ");
    scanf("%d", &unPropietario.fechaNacimiento.mes);
    printf("Anio : ");
    scanf("%d", &unPropietario.fechaNacimiento.anio);

    return unPropietario;
}

int cargarPropietario(sPropietario list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibrePropietario(list, cant);

    if(i != -1)
    {
        printf("Ingrese el nombre del propietario : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        if(r==-2)
        {
            printf("\n\nSolo es valido ingresar letras en esta casilla, ingrese al propietario de nuevo.\n\n");
            return r;
        }
        printf("Ingrese la fecha de nacimiento\n");
        printf("Dia : ");
        list[i].fechaNacimiento.dia = enterInt(list[i].fechaNacimiento.dia);
        r = onlyNumbers(list[i].fechaNacimiento.dia);
        if(r==-2)
        {
            printf("\n\nSolo es valido ingresar numeros en esta casilla, ingrese al propietario de nuevo.\n\n");
            return r;
        }
        printf("Mes : ");
        list[i].fechaNacimiento.dia = enterInt(list[i].fechaNacimiento.mes);
        printf("Anio : ");
        list[i].fechaNacimiento.dia = enterInt(list[i].fechaNacimiento.anio);
        list[i].idPropietario = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}


int buscarLibrePropietario(sPropietario list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarLibreVehiculo(sVehiculo list[],int cant)
{
    int i;
    int index = -1;
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarPropietarioPorID(sPropietario list[], int cant)
{
    int i;
    int index = -1;
    int r;
    int idNumber = 0;
    printf("\nIngrese ID del propietario : ");
    idNumber = enterInt(idNumber);
    for(i=0; i<cant; i++)
    {
        if(list[i].idPropietario == idNumber)
        {
            index = i;
            break;
        }
    }
    return index;
}

int bajarPropietario(sPropietario list[], int cant)
{
    int r = -1;
    int i;
    char respuesta;
    mostrarListadoDePropietarios(list, cant);
    i = buscarPropietarioPorID(list, cant);
    if(i != -1)
    {
        mostrarUnPropietario(list[i]);
        printf("\nPresione s para confirmar la accion.");
        respuesta = getche();
        if(respuesta == 's')
        {
            list[i].estado=LIBRE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

void mostrarUnPropietario(sPropietario unPropietario)
{
    printf("%04d %20s \t %02d/%02d/%4d\n", unPropietario.idPropietario
           , unPropietario.nombre
           , unPropietario.fechaNacimiento.dia
           , unPropietario.fechaNacimiento.mes
           , unPropietario.fechaNacimiento.anio);
}

void mostrarListadoDePropietarios(sPropietario list[], int cant)
{
    int i;
    printf("ID \t\t   NOMBRE     FECHA DE NACIMIENTO\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnPropietario(list[i]);
        }

    }
}

int modificarPropietario(sPropietario list[], int cant)
{
    int i;
    int opcion;
    int r = -1;
    mostrarListadoDePropietarios(list, cant);
    i = buscarPropietarioPorID(list, cant);
    if(i != -1)
    {
        mostrarUnPropietario(list[i]);
        printf("\n\n¿Que desea modificar?\n\n");
        printf("1. Nombre.\n");
        printf("2. Fecha de nacimiento\n");
        printf("Elija una opcion : ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("\nIngrese el nuevo nombre : ");
            enterString(list[i].nombre);
            r = 0;
            break;
        case 2:
            printf("\n\nIngrese la nueva fecha de nacimiento\n");
            printf("Dia : ");
            list[i].fechaNacimiento.dia = enterInt(list[i].fechaNacimiento.dia);
            printf("Mes : ");
            list[i].fechaNacimiento.mes = enterInt(list[i].fechaNacimiento.mes);
            printf("Anio : ");
            list[i].fechaNacimiento.anio = enterInt(list[i].fechaNacimiento.anio);
            r = 0;
            break;
        default:
            r = 1;
        }
    }
    return r;
}

int cargarVehiculo(sVehiculo list[], int cant)
{
    int i;
    int r = -1;
    i = buscarLibreVehiculo(list, cant);

    if(i != -1)
    {
        list[i] = pedirVehiculo();
        list[i].estado = OCUPADO;
        r = 0;
    }

    return r;
}


sVehiculo pedirVehiculo()
{
    sVehiculo unVehiculo;

    printf("Ingrese patente del vehiculo : ");
    enterString(unVehiculo.patente);

    printf("Ingrese la fecha de ingreso\n");
    printf("Dia : ");
    scanf("%d",&unVehiculo.fechaIngreso.dia);
    printf("Mes : ");
    scanf("%d",&unVehiculo.fechaIngreso.mes);
    printf("Anio : ");
    scanf("%d",&unVehiculo.fechaIngreso.anio);

    printf("Ingrese la hora de entrada : ");
    scanf("%d", &unVehiculo.horaIngreso);

    printf("Ingrese el ID del propietario : ");
    scanf("%d", &unVehiculo.idPropietario);

    return unVehiculo;
}

int bajarVehiculo(sVehiculo listV[],sPropietario listP[], int cant)
{
    int r = -1;
    int i;
    char respuesta;
    int horaSalida;
    mostrarListadoDeVehiculos(listV,listP, cant);
    i = buscarVehiculoPorPatente(listV, cant);
    if(i != -1)
    {
        mostrarUnVehiculo(listV[i],listP,cant);
        printf("Ingrese la hora de salida : ");
        horaSalida = enterInt(horaSalida);
        printf("\nPresione s para confirmar la accion.");
        respuesta = getche();
        if(respuesta == 's' || respuesta == 'S')
        {
            listV[i].horaSalida = horaSalida;
            cobrarPorAuto(listV, listP, cant, i);
            listV[i].estado=LIBRE;
            r = 0;
        }
        else
        {
            r = 1;
        }
    }
    return r;
}

void mostrarUnVehiculo(sVehiculo unVehiculo, sPropietario listP[], int cant)
{
    int i;
    printf("%s    %02d/%02d/%4d \t\t %02d ", unVehiculo.patente
           ,unVehiculo.fechaIngreso.dia
           ,unVehiculo.fechaIngreso.mes
           ,unVehiculo.fechaIngreso.anio
           ,unVehiculo.horaIngreso);

    for(i=0; i<cant; i++)
    {
        if(unVehiculo.idPropietario == listP[i].idPropietario)
        {
            printf("%20s \n", listP[i].nombre);
            break;
        }
    }

}

void mostrarListadoDeVehiculos(sVehiculo listV[],sPropietario listP[],int cant)
{
    int i;
    printf("PATENTE\t FECHA DE INGRESO   HORA INGRESO  \t DUENIO\n");
    for(i=0; i<cant; i++)
    {
        if(listV[i].estado == OCUPADO)
        {
            mostrarUnVehiculo(listV[i],listP, cant);
        }
    }
}

int buscarVehiculoPorPatente(sVehiculo list[], int cant)
{
    int i;
    int index = -1;
    char patente[10];
    printf("\nIngrese patente del vehiculo : ");
    enterString(patente);
    for(i=0; i<cant; i++)
    {
        if(strcmp(patente, list[i].patente) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

void hardcodeoVehiculos(sVehiculo list[], int cant)
{
    int i;
    char patente[][10]= {"AAA111", "BBB222", "AAA222", "WWW777",
                         "AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"
                        };
    int dia = {26};
    int mes = {9};
    int anio = {2019};
    int horaIngreso[] = {10,9,8,11,10,11,9,7,7,14};
    int idPropietario[]= {3,4,1,2,4,3,2,1,1,2};

    for(i=0; i<cant; i++)
    {
        strcpy(list[i].patente,patente[i]);
        list[i].fechaIngreso.dia = dia;
        list[i].fechaIngreso.mes = mes;
        list[i].fechaIngreso.anio = anio;
        list[i].horaIngreso = horaIngreso[i];
        list[i].idPropietario = idPropietario[i];
        list[i].estado = OCUPADO;
    }
}

int ordenarPersonasPorNombreAndAnio(sPropietario list[],int cant)
{
    sPropietario auxPropietario;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(list[i].nombre, list[j].nombre) > 0)
                {
                    //De A - Z
                    auxPropietario = list[i];
                    list[i] = list[j];
                    list[j] = auxPropietario;
                }

            }
            for(j=i+1; j<cant; j++)
            {
                //De menor a mayor kj
                if(strcmp(list[i].nombre, list[j].nombre) == 0 && list[i].fechaNacimiento.anio > list[j].fechaNacimiento.anio)
                {
                    auxPropietario = list[i];
                    list[i] = list[j];
                    list[j] = auxPropietario;
                }
            }
        }
        r = 0;
    }

    return r;
}

int ordenarVehiculosPorDuenioAndPatente(sVehiculo listV[], int cant)
{
    int r = -1;
    int i;
    int j;
    sVehiculo auxVehiculo;
    if(cant > 0 && listV != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(listV[i].idPropietario > listV[j].idPropietario)
                {
                    auxVehiculo = listV[i];
                    listV[i] = listV[j];
                    listV[j] = auxVehiculo;
                }
                if(listV[i].idPropietario == listV[j].idPropietario)
                {
                    if(strcmp(listV[i].patente, listV[j].patente) > 0)
                    {
                        auxVehiculo = listV[i];
                        listV[i] = listV[j];
                        listV[j] = auxVehiculo;
                    }
                }


            }
        }
        r = 0;
    }
    return r;
}

int mostrarVehiculosDeUnDuenio(sVehiculo listV[],sPropietario listP[], int cantV, int cantP)
{
    int i;
    int j;
    int r = -1;
    mostrarListadoDePropietarios(listP, cantP);
    i = buscarPropietarioPorID(listP, cantP);
    if(i!=-1)
    {
        for(j=0; j<cantV; j++)
        {
            if(listV[j].idPropietario == listP[i].idPropietario)
            {
                mostrarUnVehiculo(listV[j],listP,cantV);
            }
        }
        r = 0;
    }
    return r;
}

void cobrarPorAuto(sVehiculo listV[],sPropietario listP[], int cant, int i)
{
    int laPlata;
    laPlata = listV[i].horaSalida - listV[i].horaIngreso;
    laPlata = laPlata * 100;
    printf("\nEl total por su estadia es $ %d \n\n", laPlata);
}

