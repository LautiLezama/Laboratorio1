#include "utn.h"
#define E 20
#define J 211
#define R 10
#define P 10


int main()
{
    sJugadores listJugadores[J];
    sEquipos listEquipos[E];
    sReferi listReferees[R];
    sPartidos listPartidos[P];
    int opcion;
    int idJugadores= 1;
    int idEquipos = 1;
    int idReferee = 1;
    int idPartidos = 1;
    int r;

    if((inicializarEquipos(listEquipos, E)==0 && inicializarJugadores(listJugadores, J)==0) &&
            (inicializarReferees(listReferees, R)==0 && inicializarPartidos(listPartidos, P)==0))
    {
        do
        {


            printf("Que desea hacer\n\n");
            printf("1.ALTA EQUIPO\n");
            printf("2.LISTAR EQUIPOS\n");
            printf("3.ALTA JUGADOR\n");
            printf("4.LISTAR JUGADORES\n");
            printf("5.ALTA REFEREE\n");
            printf("6.ALTA PARTIDO\n");
            printf("7.LISTAR PARTIDOS\n");
            printf("8. SALIR\n");
            printf("Ingrese una opcion : ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                r=cargarEquipo(listEquipos, E,idEquipos);
                if(r==0)
                {
                    printf("Equipo cargado.\n");
                    idEquipos ++;

                }
                else
                {
                    printf("No hay mas espacio de equipos.\n");
                }
                break;
            case 2:
                ordenarEquiposPorNombre(listEquipos, E);
                mostrarListadoDeEquipos(listEquipos, E);
                break;
            case 3:
                r=cargarJugador(listJugadores,listPartidos, J,P,idJugadores);
                if(r==0)
                {
                    printf("Jugador cargado exitosamente.\n\n");
                    idJugadores++;

                }
                else
                {
                    printf("No hay mas espacio de jugadores\n\n");
                }


                break;
            case 4:
                ordenarJugadoresPorApellido(listJugadores, J);
                mostrarListadoDeJugadores(listJugadores,J);
                break;
            case 5:
                r= cargarReferi(listReferees, R,idReferee);
                if(r==0)
                {
                    printf("Referi cargado\n");
                    idReferee ++;
                }
                else
                {
                    printf("No hay mas espacio de referees\n");
                }

                break;
            case 6:
                r = cargarPartido(listPartidos,listEquipos,listReferees, P,E,R,idPartidos);
                if(r==0)
                {
                    printf("Partido cargado\n");
                    idPartidos ++;
                }
                else
                {
                    printf("No hay mas espacio de partidos.");
                }
                break;
            case 7:
                ordenarPartidosPorFecha(listPartidos, P);
                mostrarListadoDePartidos(listPartidos, P);
                break;
            default:
                printf("\nNo has elegido una opcion valida.\n\n");
                break;


            }
        }
        while(opcion != 8);
    }
    else
    {
        printf("\nNo se pudo iniciar el menu\n");
    }

    return 0;
}
