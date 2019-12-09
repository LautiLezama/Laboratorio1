#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 5

typedef struct
{
    int idAlien;
    float coordX;
    float coordY;
    char raza[50];
    char galaxia[50];
}sAlien;

sAlien* nuevoAlien();
sAlien* nuevoAlienParametrizado(int,float,float,char*,char*);

void setId(sAlien*,int);
void setCoordX(sAlien*,float);
void setCoordY(sAlien*,float);
void setRaza(sAlien*,char*);
void setGalaxia(sAlien*,char*);

void getId(sAlien*,int*);
void getCoordX(sAlien*, float*);
void getCoordY(sAlien*,float*);
void getRaza(sAlien*,char*);
void getGalaxia(sAlien*,char*);

int escribirAliens(sAlien** lista, int tam, char* path);
sAlien* leerAliens(char* path,sAlien* lista[]);

int main()
{
    sAlien* listaAliens[CANT];
    /*int id[] = {1,2,3,4,5};
    float coordsX[] = {23.4,77.7,16.6,93.3,64.3};
    float coordsY[] = {84.3,12.87,95.34,56.4,78.3};
    char raza[][50] = {"Messi","Riquelme","Neymar","Suarez","Buffarini"};
    char galaxia[][50] = {"Barcelona","BokitaElMasGrande","PSG","Charrua","SanSilencio"};

    int i;
    for(i=0;i<CANT;i++)
    {
        listaAliens[i] = nuevoAlienParametrizado(id[i],coordsX[i],coordsY[i],galaxia[i],raza[i]);
    }
    escribirAliens(listaAliens,CANT,"archivoAliens.bin");*/
    leerAliens("archivoAliens.bin",listaAliens);


        mostrarUnAlien(listaAliens);

    return 0;
}

sAlien* nuevoAlien()
{
    sAlien* unAlien;
    unAlien = (sAlien*)malloc(sizeof(sAlien));
    return unAlien;
}

void setId(sAlien* unAlien,int num1)
{

         unAlien->idAlien = num1;

}

void setCoordX(sAlien* unAlien,float num1)
{
    unAlien->coordX = num1;
}

void setCoordY(sAlien* unAlien,float num1)
{
 unAlien->coordY = num1;

}

void setGalaxia(sAlien* unAlien, char* char1)
{

        strcpy(unAlien->galaxia,char1);

}

void setRaza(sAlien* unAlien, char* char1)
{

        strcpy(unAlien->raza,char1);

}

void getId(sAlien* unAlien,int* num1)
{
    *num1 = unAlien->idAlien;

}

void getCoordX(sAlien* unAlien,float* num1)
{
    *num1 = unAlien->coordX;

}

void getCoordY(sAlien* unAlien,float* num1)
{

    *num1 = unAlien->coordY;

}

void getGalaxia(sAlien* unAlien, char* char1)
{
    strcpy(char1,unAlien->galaxia);

}

void getRaza(sAlien* unAlien, char* char1)
{
    strcpy(char1,unAlien->raza);

}

sAlien* nuevoAlienParametrizado(int id, float coordX, float coordY, char* galaxia, char* raza)
{
    sAlien* aux;
    aux = nuevoAlien();

    setId(aux,id);
    setCoordX(aux,coordX);
    setCoordY(aux,coordY);
    setGalaxia(aux,galaxia);
    setRaza(aux,raza);

    return aux;
}


int escribirAliens(sAlien** lista, int tam, char* path)
{
    int r=-1;
    int i;
    FILE* elArchivo;

    if(lista != NULL)
    {
        elArchivo = fopen(path,"wb");
        for(i=0;i<tam;i++)
        {
          fwrite((void*)lista[i],sizeof(sAlien),1,elArchivo);
        }
        fclose(elArchivo);
        r = 0;
    }

    return r;
}


sAlien* leerAliens(char* path,sAlien* lista[])
{
  int i=0;
    int ret=-1;
    int r=0;
    FILE* pFile;
    sAlien* pAlien=nuevoAlien();
    int auxID=0;
    float auxCoordY=0;
    float auxCoordX=0;
    char auxRaza[20];
    char auxGalaxia[20];

    if(path!=NULL)
    {
        pFile=fopen(path,"rb");

        while(!feof(pFile))
        {

            r = fread(pAlien,sizeof(sAlien),1,pFile);
            if (r!=1)
            {
                break;
            }else
            {
                getId(pAlien,&auxID);
                getCoordY(pAlien,&auxCoordY);
                getCoordX(pAlien,&auxCoordX);
                getRaza(pAlien,auxRaza);
                getGalaxia(pAlien,auxGalaxia);

                lista[i]=(sAlien*)nuevoAlienParametrizado(pAlien->idAlien,pAlien->coordY,pAlien->coordX,pAlien->raza,pAlien->galaxia);

                printf("%d--%.02f--%.02f--%s--%s\n",auxID,auxCoordY,auxCoordX,auxRaza,auxGalaxia);

                i++;
            }

        }
        fclose(pFile);
    }
    return ret;
}

void mostrarUnAlien(sAlien* lista[])
{
    int i;
    for(i=0;i<CANT;i++)
    {
         printf("%d--%f--%f--%s--%s \n",lista[i]->idAlien,lista[i]->coordX,lista[i]->coordY,lista[i]->raza,lista[i]->galaxia);
    }

}








