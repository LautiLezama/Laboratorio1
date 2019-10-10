#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1


typedef struct
{
    int dia;
    int mes;
    int anio;
} sFecha;

typedef struct
{
    int codigo;
    char nombre[51];
    char localidad[33];
    int estado;
} sEquipos;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    int codigoDeEquipo;
    char sexo;
    sFecha fechaNacimiento;
    int estado;
} sJugadores;

typedef struct
{
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char eMail[31];
    sFecha fechaNacimiento;
    int estado;
} sReferi;

typedef struct
{
    int codigo;
    int codigoDeEquipoVisitante;
    int codigoDeEquipoLocal;
    int codigoDeReferi;
    sFecha fechaDePartido;
    int estado;
} sPartidos;

int positivoInt(char []);
int onlyLetters(char []);
char* enterString(char*);


//Equipos
int inicializarEquipos(sEquipos [], int);
int cargarEquipo(sEquipos [], int, int);
int buscarLibreEquipos(sEquipos [], int);
void mostrarUnEquipo(sEquipos);
void mostrarListadoDeEquipos(sEquipos [], int);
int ordenarEquiposPorNombre(sEquipos [],int);


//Jugadores
int inicializarJugadores(sJugadores [], int);
int cargarJugador(sJugadores [],sEquipos[],int, int, int);
int buscarLibreJugadores(sJugadores [], int);
void mostrarUnJugador(sJugadores);
void mostrarListadoDeJugadores(sJugadores [], int);
int ordenarJugadoresPorApellido(sJugadores [],int);

//Referees
int inicializarReferees(sReferi [], int);
int cargarReferi(sReferi [], int, int);
int buscarLibreReferees(sReferi [], int);
void mostrarUnReferee(sReferi);
void mostrarListadoDeReferees(sReferi [], int);


//Partidos
int inicializarPartidos(sPartidos [], int);
int cargarPartido(sPartidos [],sEquipos[],sReferi[],int,int,int, int);
int buscarLibrePartidos(sPartidos [], int);
void mostrarUnPartido(sPartidos);
void mostrarListadoDePartidos(sPartidos [], int);
int ordenarPartidosPorFecha(sPartidos [],int cant);
