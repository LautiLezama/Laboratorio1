#include <stdio.h>
#include <stdlib.h>

int main()
{
    float altura;
    int edad;
    char sexo;
    float altvieja;
    char respuesta = 's';
    int contador = 0;
    int edadvieja = 0;
    float alturajoven;
    int edadjoven;
    char sexoalto;
    float alturamax;
    int edadhombrebajo;
    float alturahombrebajo = 2;
    int acumuladoredad = 0;
    float promedioedad = 0;
    float acumuladoralth = 0;
    float promedioalth = 0;
    int contadoralth = 0;


    while(respuesta == 's')
    {

        printf("\n ingrese su altura:");
        scanf("%f", &altura);

        while(altura > 2 || altura < 1)
        {

            printf("Altura invalida, ingrese altura: ");
            scanf("%f", &altura);
        }

        printf("Ingrese su edad:");
        scanf("%d", &edad);

        while(edad < 0 || edad > 120)
        {
            printf("Edad invalida, ingrese edad: ");
            scanf("%d", &edad);
        }

        printf("Ingrese su sexo: f/m");
        sexo = getche();

        while (sexo != 'f' && sexo != 'm')
        {

            printf("Ingrese su sexo: f/m");
            sexo = getche();
        }

        if (sexo == 'f' && edadvieja < edad)
        {
            altvieja = altura;
            edadvieja = edad;
        }

        if (contador == 0)
        {

            edadjoven = edad;
            alturajoven = altura;
            sexoalto = sexo;
            alturamax = altura;

        }

        if (edad < edadjoven)
        {

            edadjoven = edad;
            alturajoven = altura;
        }

        if (altura > alturamax)
        {

            sexoalto = sexo;
            alturamax = altura;
        }

        if (altura < alturahombrebajo && sexo == 'm')
        {

            edadhombrebajo = edad;
            alturahombrebajo = altura;
        }


        if (sexo == 'm')
        {

            acumuladoralth = acumuladoralth + altura;
            contadoralth ++;
        }

        acumuladoredad = acumuladoredad + edad;

        contador ++;

        fflush(stdin);

        printf("\n Quiere continuar? s/n");
        respuesta = getche();

    }

    promedioedad = acumuladoredad / contador;
    promedioalth = acumuladoralth / contadoralth;

    printf("\nla mujer mas vieja mide %f ", altvieja);
    printf("\nla altura del mas joven es %f ", alturajoven);
    printf("\nel sexo de la persona mas alta es %c ", sexoalto);
    printf("\nedad del hombre mas bajo es %d ", edadhombrebajo);
    printf("\npromedio de edades es %d ", promedioedad);
    printf("\npromedio de alturas de los hombres es %f", promedioalth);


}
