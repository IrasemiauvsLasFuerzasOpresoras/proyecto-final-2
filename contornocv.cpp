#include "contornocv.h"
// MOSTRAR IMAGEN EN CONTORNO

cv::Mat Contorno(){
    cv::Mat image= cv::imread("/home/citlali/Proyecto_progra/Bi_oro.pgm");
    cv::Mat contours;
    cv::Mat gray_image;

    cvtColor( image, gray_image, CV_RGB2GRAY );

    cv::Canny(image,contours,10,350);
    cv::namedWindow("Contorno");
    cv::imshow("Contorno",contours);
    cv::waitKey(0);

    Mat imagen;     // Matriz que guardara la imagen
    imagen = contours;
return contours;
}

int muestra(){

    FILE *fichero;
    int *matriz;
    int c,i; // note: int, not char, required to handle EOF
    // char nombre[20]="Dp_oro.pgm";
    fichero = fopen(nombre, "r" );

    //FILE* fp = std::fopen("prueba.txt", "r");
    if(!fichero) {
        std::perror("fallo al abrir");
        return EXIT_FAILURE;
    }

    matriz=&c;
    cout<<&matriz<<endl;
    i=0;
    while ((c = std::fgetc(fichero)) != EOF) { // standard C I/O file reading loop
       //std::putchar(c);
        cout<<*(matriz)<<endl;

    }

    if (std::ferror(fichero))
        std::puts("I/O error al leer");

    else if (std::feof(fichero))
        std::puts("fin satisfactorio");

    std::fclose(fichero);
     return *(matriz);
}
