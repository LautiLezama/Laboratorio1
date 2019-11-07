#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE* pArchive;
    int a[3];
    char miNombre[50];
    int i;
    char aux[50];



    /*pArchive = fopen("nuevoArchivo.bin","wb");
    fwrite(a,sizeof(int),3,pArchive);*/

    pArchive = fopen("nuevoArchivo.bin","rb");
    fread(a,sizeof(int),3,pArchive);
    for(i=0;i<3;i++)
    {
        printf("%d \n", a[i]); ///Estas mostrando los numeros del archivo, no del codigo.
    }


    /*fprintf(pArchive,"Pepe\n");
    fprintf(pArchive,"Fatiga\n");
    fprintf(pArchive,"Moni");*/

    /*pArchive = fopen("nuevoArchivo.txt","r");

    while(!feof(pArchive)) //Mientras no se termine de leer el archivo leer todas las lineas en consola.
    {
        fgets(aux,50,pArchive);
        strcpy(miNombre[i],aux);
        i++;
    }*/

    fclose(pArchive);

    /*for(i=0;i<3;i++)
    {
        printf("%s", miNombre[i]);
    }*/



    return 0;
}

/*

feof() = se mantiene en true hasta que termina el archivo.


*/
