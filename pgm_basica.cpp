#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <time.h>
#include "pgm_basica.h"

using namespace std;

int main(int argc, char *argv[]){

    IMAGEN ima;
    IMAGEN otra;
    char nombre[20];
    int tipo;

    cout<<"Ingresa el nombre de la imagen"<<endl;
    cin>>nombre;

    tipo = es_pgm(nombre);

    if(tipo == 1)
    {
        ima = lee_imagen(nombre);
        cout<<endl;
        muestra_datos_imagen(&ima);
        cout<<endl;
        otra = duplica_imagen(&ima);
        cout<<endl;
        muestra_datos_imagen(&otra);
        cout<<endl;
        binariza_imagen(&otra, 128);
        cout<<endl;
        // recubrimiento(&otra);
        cout<<endl;
        grabaimagen(&otra);
        cout<<endl;
    }
    cout<<endl;
}
