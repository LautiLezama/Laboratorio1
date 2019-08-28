#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    /*Mujer mas vieja
Altura persona mas joven
Sexo de la persona mas alta
Edad del hombre mas bajo
Promedio de edades
Promedio de alturas de hombres */


int edad;
float altura;
char sexo;
char respuesta = 's';
int contador = 0;
//Altura de la mas vieja
int edadMasVieja;
float alturaMasVieja;
int flagPrimeraVieja = 0;
//Altura de la persona mas joven + contador
int edadMasJoven;
float alturaMasJoven;
//Sexo de la persona mas alta + contador
char sexoMasAlto;
float alturaMasAlto;
//Edad del hombre mas bajo
float alturaMasBajo;
int edadMasBajo;
int flagMasBajo = 0;
//Promedio de Edades + contador
float promedioEdades;
int acumuladorEdades = 0;
//Promedio de alturas de hombres
float promedioAlturasHombres;
float acumuladorAlturasHombres = 0;
int contadorHombres = 0;





do{

//Pido datos

    printf("\nIngrese la edad : ");
    scanf("%d",&edad);

    while(edad > 120 || edad < 0){

         printf("Reingrese la edad : ");
         scanf("%d",&edad);
    }

    printf("Ingrese la altura : ");
    scanf("%f", &altura);

    while(altura < 1 || altura > 2){

        printf("Reingrese la altura : ");
        scanf("%f", &altura);
    }

    printf("Ingrese el sexo : ");
    sexo = getche();

    while(sexo != 'f' && sexo != 'm'){

        printf("\nReingrese el sexo : ");
        sexo = getche();
    }

    //Mujer mas vieja

    if(sexo == 'f'){

        if(flagPrimeraVieja == 0 || edad > edadMasVieja){

            edadMasVieja = edad;
            alturaMasVieja = altura;
            flagPrimeraVieja = 1;
        }
    }

    //Altura de la persona más joven

    if(contador == 0 || edad < edadMasJoven){

        edadMasJoven = edad;
        alturaMasJoven = altura;

    }

    //Sexo de la persona mas alta

    if(contador == 0 || altura > alturaMasAlto){

        alturaMasAlto = altura;
        sexoMasAlto = sexo;
    }

    //Edad del hombre mas bajo

    if(sexo == 'm'){

        if(flagMasBajo == 0 || altura < alturaMasBajo){

            alturaMasBajo = altura;
            edadMasBajo = edad;
            flagMasBajo = 1;

        }

        //Promedio de alturas de hombres

        acumuladorAlturasHombres = acumuladorAlturasHombres + altura;

        contadorHombres ++;


    }


    //Promedio de Edades

    acumuladorEdades = acumuladorEdades + edad;

    contador ++;

   printf("\nPresione s para continuar : ");
   respuesta = getche();

}while(respuesta == 's');

promedioEdades = (float)acumuladorEdades / contador;
promedioAlturasHombres = acumuladorAlturasHombres / contadorHombres;

printf("\nLa mujer mas vieja mide %f", alturaMasVieja);
printf("\nLa persona mas joven mide %f", alturaMasJoven);
printf("\nLa persona mas alta es %c", sexoMasAlto);
printf("\nEl hombre mas bajo tiene %d años", edadMasBajo);
printf("\nEl promedio de edades es de %f", promedioEdades);
printf("\nEl promedio de alturas de los hombres es %f \n", promedioAlturasHombres);



}
