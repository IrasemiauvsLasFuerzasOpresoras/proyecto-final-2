#ifndef PGMBASICA_H
#define PGMBASICA_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <time.h>
using namespace std;


typedef struct imagen{
    char nombre[20];
    int cant_comen;
    int ancho;
    int alto;
    int grises;
    unsigned char im[800][800];
} IMAGEN;

int es_pgm(char *nombre){
    FILE *ent;
    unsigned char c1,c2;
    printf("\nChequeando: %s\n",nombre);
    if ((ent = fopen(nombre,"rb")) ==NULL)
        return 0;
    c1=fgetc(ent);
    c2=fgetc(ent);

    fclose(ent);
    if ((c1=='P') && (c2=='5'))
        return 1;
    else
        return 0;
}

IMAGEN lee_imagen(char *nombre)
{
    IMAGEN imagen;
    unsigned int c1,c2;
    unsigned char carac;
    FILE *ent;
    int i,j, ancho,alto,grises;

    ent = fopen(nombre,"rb");
    c1=fgetc(ent);
    c2=fgetc(ent);
    fgetc(ent); //Elimina el separador
    carac=fgetc(ent);
    imagen.cant_comen=0;
    while(carac=='#'){
        imagen.cant_comen=imagen.cant_comen+1;
        carac=fgetc(ent);
        while(carac!='\n')
            carac=fgetc(ent);
        carac=fgetc(ent);
    }
    ungetc(carac,ent);
    fscanf(ent,"%d%d",&ancho,&alto);
    fscanf(ent,"%d",&grises);
    imagen.ancho = ancho;
    imagen.alto= alto;
    imagen.grises = grises;
    strcpy(imagen.nombre,nombre);
    for(i=0; i<imagen.alto;i++)
        for(j=0; j<imagen.ancho; j++){
            carac=fgetc(ent);
            imagen.im[i][j]=carac;
        }
    fclose(ent);
    return(imagen);
}

void muestra_datos_imagen(IMAGEN *imagen){
    printf("\nArchivo: %s",imagen->nombre);
    printf("\nComentarios : %d",imagen->cant_comen);
    printf("\nAncho : %d",imagen->ancho);
    printf("\nAlto  : %d",imagen->alto);
    printf("\nGrises: %d\n",imagen->grises);
}

void grabaimagen(IMAGEN *imagen){
    int i,j;
    unsigned char c;
    FILE *sal;

/*
    int nro;
    char nombre[14],nombre1[6];
    nro = (rand()%(9999 - 1000 + 1)) + 1000;
    itoa(nro,nombre1,10);
    strcpy(nombre,"Hac_");
    strcat(nombre,nombre1);
    strcat(nombre,".pgm");
*/

    printf("\nCreando : %s",imagen->nombre);
    sal=fopen(imagen->nombre,"wb");
    fprintf(sal,"P5\n");
    fprintf(sal,"# Creado por C.\n");
    fprintf(sal,"%d %d\n",imagen->ancho,imagen->alto);
    fprintf(sal,"%d\n",imagen->grises);
    for(i=0; i<imagen->alto;i++)
        for(j=0; j<imagen->ancho; j++)
        {
            c=imagen->im[i][j];
            fputc(c,sal);
            //printf(" ",imagen->im[i][j]);
        }
        //printf("");
//	fputc(final,sal);
    fclose(sal);
}

void aclara_imagen(IMAGEN *imagen, int valor){
    int i,j;
    for(i=0; i < imagen->alto; i++)
        for(j=0; j < imagen->ancho; j++)
            if ((imagen->im[i][j]+valor) > 255)
                imagen->im[i][j]=255;
            else
                imagen->im[i][j]=imagen->im[i][j] + valor;
}

void oscurece_imagen(IMAGEN *imagen, int valor){
    int i,j;
    for(i=0; i < imagen->alto; i++)
        for(j=0; j < imagen->ancho; j++)
            if ((imagen->im[i][j]-valor) <0)
                imagen->im[i][j]=0;
            else
                imagen->im[i][j]=imagen->im[i][j] - valor;
}

void negativo_imagen(IMAGEN *imagen){
    int i,j;
    for(i=0; i < imagen->alto; i++)
        for(j=0; j < imagen->ancho; j++)
            imagen->im[i][j]=255 - imagen->im[i][j];
}

void binariza_imagen(IMAGEN *imagen, int umbral){
    int i,j;
   // printf("-------lectura de imagen ---------------");
    for(i=0; i < imagen->alto; i++)
        for(j=0; j < imagen->ancho; j++)
            if (imagen->im[i][j] < umbral){
                imagen->im[i][j]=0;
               // printf("0");
                 }
               else{
                imagen->im[i][j]= 255;
                 //    printf("1");
                 }
}

void imprime_imagen(IMAGEN *imagen, int umbral){
    int i,j;
    printf("-------lectura de imagen ---------------");
    cout<<endl;
    for(i=0; i < imagen->alto; i++){
     printf(" ");
        for(j=0; j < imagen->ancho; j++){
            if (imagen->im[i][j] < umbral)

                printf("1");
               else
                printf("0");}
            cout<<endl;
    }

}
void cuenta_ceros(IMAGEN *imagen, int umbral){
     int i,j;
     int p;
     int contador=0;
     float perimetro;
     float restante;
     float final;
     int x=imagen->alto;
     int y=imagen->ancho;
     int datos[x][y];
     int datos1[x][y];
    printf("-------lectura de imagen ---------------");
    //cout<<endl;
    for(i=0; i < x ; i++){
       for(j=0; j < y; j++)
            if (imagen->im[i][j] < umbral)
                datos[i][j]=1;
            else
                datos[i][j]=0;
        }

    //cuenta unos horizontal
    p=0;
    for(i=0; i < x ; i++){
        for(j=0; j < y; j++){
           if(p != datos[i][j])
               datos1[i][j]=7;
           else
              datos1[i][j]=0;
          p=datos[i][j];
        }
     }
    //cuenta unos vertical
    for(j=0; j < x ; j++){
        for(i=0; i < y ; i++){
            if(p != datos[i][j])
            datos1[i][j]=7;
           else{
              if (datos1[i][j]!=7)
                  datos1[i][j]=0;}
             p=datos[i][j];
        }
        //cout<<endl;
       }
//Cuenta total
    contador=0;
      for(i=0; i < x ; i++)
          for(j=0; j < y ; j++)
              if( datos1[i][j]==7)
                contador++;



    //imprime ceros
    for(i=0; i < x; i++){
        printf(" \n");
       for(j=0; j < y; j++)
            printf("%i ",datos[i][j]);

}
   restante= (contador-1)/4;
   perimetro= contador-restante;
   final=perimetro/10;

    cout<<endl<<"El perímetro de cada partícula en nanometros es: ";
     printf("%.2f",final); cout<<"nm.";



}

void histograma(IMAGEN *imagen){
    int i,j;
    int mayor;
    float aux;
    int histo[256];
    for (i=0; i< imagen->alto; i++)
        for(j=0; j< imagen->ancho; j++)
            histo[imagen->im[i][j]]=histo[imagen->im[i][j]]+1;

    mayor = 0;
    for(i=0; i<256; i++)
       if (histo[i]>mayor)
            mayor = histo[i];

    for (i=0; i<256; i++){
        aux=(float)(histo[i])/mayor;
        aux=aux*100*2;
        histo[i] = (int)(aux);
    }

}

IMAGEN laplaciano(IMAGEN *imagen){
    IMAGEN ret;
    int numero;
    char nro[3];

    int m[3][3],i,j,k,l,s;
    m[0][0]= 0; m[0][1]=-1; m[0][2]= 0;
    m[1][0]=-1; m[1][1]=-4; m[1][2]=-1;
    m[2][0]= 0; m[2][1]=-1; m[2][2]= 0;

    for(i=1; i< imagen->alto-2; i++){
        for(j=1; j< imagen->ancho-2; j++){
            s=0;
            for(k=0; k<3; k++)
                for(l=0; l<3; l++)
                    s=s+m[k][l]*(imagen->im[i+k][j+l]);
        }
        ret.im[i][j]= s;
    }

    strcpy(ret.nombre,"Lp_");
    strcat(ret.nombre,imagen->nombre);
    ret.cant_comen = imagen->cant_comen;
    ret.ancho      = imagen->ancho;
    ret.alto       = imagen->alto;
    ret.grises     = imagen->grises;
    return ret;
}

IMAGEN duplica_imagen(IMAGEN *imagen){
    IMAGEN ret;
    int i,j;
    printf("\nDuplicando: %s\n",imagen->nombre);
    strcpy(ret.nombre,"Bi_");
    strcat(ret.nombre,imagen->nombre);
    ret.cant_comen = imagen->cant_comen;
    ret.ancho      = imagen->ancho;
    ret.alto       = imagen->alto;
    ret.grises     = imagen->grises;
    for(i=0; i<imagen->alto; i++)
        for(j=0; j<imagen->ancho; j++){
            ret.im[i][j]=imagen->im[i][j];
            //printf(" xxxx ",ret.im[i][j]);
        }
    return ret;
}

#endif // PGMBASICA_H
