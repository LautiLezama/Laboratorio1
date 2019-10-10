#include "utn.h"
char* enterString(char* string1)
{
    fflush(stdin);
    gets(string1);
    return string1;
}

int onlyLetters(char string1[])
{
    int i;
    int largo;
    int r = 0;
    largo = strlen(string1);
    for(i=1; i<largo; i++)
    {
        if(string1[i]==32)
        {
            continue;
        }
        if(((string1[i]<97 && string1[i]>90) || string1[i]>122) || string1[i]<65)
        {
            r = -2;
            return r;
        }
    }
    return r;
}

int positivoInt(char mensaje[])
{
    char snum[10];
    int i;
    int r;
    do
    {
        printf(mensaje);
        fflush(stdin);
        gets(snum);
        for(i=0; snum[i]!='/0'; i++)
        {
            if(snum[i] < 48 || snum[i] > 57)
            {
                printf("Ingrese un valor valido(Solo numeros positivos).");
                r = -2;
                break;
            }
        }

    }
    while(r==-2);
    r=atoi(snum);
    return r;
}

int inicializarEquipos(sEquipos list[], int cant)
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

int inicializarJugadores(sJugadores list[], int cant)
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

int inicializarReferees(sReferi list[], int cant)
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

int inicializarPartidos(sPartidos list[], int cant)
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

int buscarLibreEquipos(sEquipos list[],int cant)
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

int buscarLibreJugadores(sJugadores list[],int cant)
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

int buscarLibreReferees(sReferi list[],int cant)
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

int buscarLibrePartidos(sPartidos list[],int cant)
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

int cargarPartido(sPartidos listP[],sEquipos listE[],sReferi listR[],int cantP,int cantE,int cantR,int idNumber)
{
    int i;
    int j;
    int r1 = -1;
    int r = -1;
    i = buscarLibrePartidos(listP, cantP);

    if(i != -1)
    {


        listP[i].codigoDeEquipoLocal = positivoInt("Ingrese el codigo del equipo local : ");



        listP[i].codigoDeEquipoVisitante = positivoInt("Ingrese el codigo del equipo local : ");



        listP[i].codigoDeReferi = positivoInt("Ingrese el codigo del equipo local : ");


        listP[i].codigoDeEquipoVisitante = positivoInt("Ingrese el codigo del equipo visitante : ");
        listP[i].codigoDeReferi = positivoInt("Ingrese el codigo del equipo referi : ");
        printf("Ingrese la fecha del partido \n");
        listP[i].fechaDePartido.dia = positivoInt("Dia : ");
        listP[i].fechaDePartido.mes = positivoInt("Mes : ");
        listP[i].fechaDePartido.anio = positivoInt("Anio : ");
        listP[i].codigo = idNumber;
        listP[i].estado = OCUPADO;
        listP[i].codigo = idNumber;
        listP[i].estado = OCUPADO;
    }

    return r;
}

int cargarEquipo(sEquipos list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreEquipos(list, cant);

    if(i != -1)
    {
        printf("Ingrese el nombre del equipo : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese nombre: ");
            enterString(list[i].nombre);
            r = onlyLetters(list[i].nombre);
        }
        printf("Ingrese la localidad del equipo : ");
        enterString(list[i].localidad);
        r = onlyLetters(list[i].localidad);
        while(r==-2)
        {
            printf("Solo se aceptan letras y espacio, reingrese localidad: ");
            enterString(list[i].localidad);
            r = onlyLetters(list[i].localidad);
        }
        r = 0;
        list[i].codigo = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}

int cargarJugador(sJugadores listJ[],sEquipos listE[],int cantJ,int cantE,int idNumber)
{
    int i;
    int r = -1;
    int r1 = -1;
    int j;
    i = buscarLibreJugadores(listJ, cantJ);

    if(i != -1)
    {
        printf("Ingrese el apellido del jugador : ");
        enterString(listJ[i].apellido);
        r = onlyLetters(listJ[i].apellido);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese apellido: ");
            enterString(listJ[i].apellido);
            r = onlyLetters(listJ[i].apellido);
        }

        printf("Ingrese el nombre del jugador : ");
        enterString(listJ[i].nombre);
        r = onlyLetters(listJ[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese nombre: ");
            enterString(listJ[i].nombre);
            r = onlyLetters(listJ[i].nombre);
        }

        printf("Ingrese el codigo de su equipo : ");
        scanf("%d", &listJ[i].codigoDeEquipo);
    //listJ[i].codigoDeEquipo = positivoInt("Ingrese el codigo de su equipo : ");
        printf("Ingrese su sexo : ");
       getche(listJ[i].sexo);
        printf("Ingrese su fecha de nacimiento \n");
        printf("Dia : ");
        scanf("%d", &listJ[i].fechaNacimiento.dia);
        printf("Dia : ");
        scanf("%d", &listJ[i].fechaNacimiento.mes);
        printf("Dia : ");
        scanf("%d", &listJ[i].fechaNacimiento.anio);
        listJ[i].codigo = idNumber;
        listJ[i].estado = OCUPADO;
    }

    return r;
}

int cargarReferi(sReferi list[],int cant,int idNumber)
{
    int i;
    int r = -1;
    i = buscarLibreReferees(list, cant);

    if(i != -1)
    {
        printf("Ingrese el apellido del referi : ");
        enterString(list[i].apellido);
        r = onlyLetters(list[i].apellido);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese apellido: ");
            enterString(list[i].apellido);
            r = onlyLetters(list[i].apellido);
        }

        printf("Ingrese el nombre del referi : ");
        enterString(list[i].nombre);
        r = onlyLetters(list[i].nombre);
        while(r==-2)
        {
            printf("Solo se aceptan letras, reingrese nombre: ");
            enterString(list[i].nombre);
            r = onlyLetters(list[i].nombre);
        }

        printf("Ingrese su sexo : ");
        getche(list[i].sexo);
        while(list[i].sexo != 'f' && list[i].sexo != 'm')
        {
            printf("Sexo invalido, reingrese : ");
            getche(list[i].sexo);
        }

        printf("Ingrese su eMail : ");
        gets(list[i].eMail);

        printf("Ingrese su fecha de nacimiento \n");
        list[i].fechaNacimiento.dia = positivoInt("Dia : ");
        list[i].fechaNacimiento.mes = positivoInt("Mes : ");
        list[i].fechaNacimiento.anio = positivoInt("Anio : ");

        list[i].codigo = idNumber;
        list[i].estado = OCUPADO;
    }

    return r;
}

void mostrarUnEquipo(sEquipos unEquipo)
{
    printf("%03d %20s \t %20s \n", unEquipo.codigo
           , unEquipo.nombre
           , unEquipo.localidad);
}


void mostrarListadoDeEquipos(sEquipos list[], int cant)
{
    int i;
    printf("CODIGO \t\t   NOMBRE   \t\t  LOCALIDAD\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnEquipo(list[i]);
        }

    }
}

void mostrarUnJugador(sJugadores unJugador)
{
    printf("%03d %20s \t %20s \t %03d \t %c  %02d/%02d/%4d\n", unJugador.codigo
           , unJugador.nombre
           , unJugador.apellido
           , unJugador.codigoDeEquipo
           , unJugador.sexo
           , unJugador.fechaNacimiento.dia
           , unJugador.fechaNacimiento.mes
           , unJugador.fechaNacimiento.anio);
}
void mostrarListadoDeJugadores(sJugadores list[], int cant)
{
    int i;
    printf("CODIGO \t  NOMBRE  \t   APELLIDO  \t COD EQUIPO \t SEXO   FECHA NACIMIENTO \n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnJugador(list[i]);
        }

    }
}

void mostrarUnReferee(sReferi unReferi)
{
    printf("%03d %20s \t %20s \t %c \t %20s \t %02d/%02d/%4d\n", unReferi.codigo
           , unReferi.nombre
           ,unReferi.apellido
           ,unReferi.sexo
           ,unReferi.eMail
           , unReferi.fechaNacimiento.dia
           , unReferi.fechaNacimiento.mes
           , unReferi.fechaNacimiento.anio);
}

void mostrarListadoDeReferees(sReferi list[], int cant)
{
    int i;
    printf("CODIGO \t   NOMBRE  \t APELLIDO  \t SEXO    EMAIL \t   FECHA DE NACIMIENTO\n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnReferee(list[i]);
        }

    }
}

void mostrarUnPartido(sPartidos unPartido)
{
    printf("%03d \t %03d  %03d  %03d  %02d/%02d/%4d\n", unPartido.codigo
           ,unPartido.codigoDeEquipoLocal
           ,unPartido.codigoDeEquipoVisitante
           ,unPartido.codigoDeReferi
           , unPartido.fechaDePartido.dia
           , unPartido.fechaDePartido.mes
           , unPartido.fechaDePartido.anio);
}

void mostrarListadoDePartidos(sPartidos list[], int cant)
{
    int i;
    printf("CODIGO \t   CODIGO LOCAL    CODIGO VISITANTE     CODIGO REFEREE     FECHA \n\n");
    for(i=0; i<cant; i++)
    {
        if(list[i].estado == OCUPADO)
        {
            mostrarUnPartido(list[i]);
        }

    }
}

int ordenarJugadoresPorApellido(sJugadores list[],int cant)
{
    sJugadores auxJugador;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(strcmp(list[i].apellido, list[j].apellido) > 0)
                {
                    //De A - Z
                    auxJugador = list[i];
                    list[i] = list[j];
                    list[j] = auxJugador;
                }
            }

        }
        r = 0;
    }
    return r;
}

int ordenarEquiposPorNombre(sEquipos list[],int cant)
{
    sEquipos auxEquipo;
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
                    auxEquipo = list[i];
                    list[i] = list[j];
                    list[j] = auxEquipo;
                }
            }

        }
        r = 0;
    }
    return r;
}

int ordenarPartidosPorFecha(sPartidos list[],int cant)
{
    sPartidos auxPartido;
    int i;
    int j;
    int r = -1;
    if(cant > 0 && list != NULL)
    {
        for(i=0; i<cant-1; i++)
        {
            for(j=i+1; j<cant; j++)
            {
                if(list[i].fechaDePartido.anio > list[j].fechaDePartido.anio)
                {
                    //De A - Z
                    auxPartido = list[i];
                    list[i] = list[j];
                    list[j] = auxPartido;
                }
            }

        }

        r = 0;
    }
    return r;
}
