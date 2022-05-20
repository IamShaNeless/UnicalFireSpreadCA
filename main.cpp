#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "surface.h"

#define STEPS 10
#define DIMENSION 10

using namespace std;

Surface* readMatrix = new Surface(DIMENSION, DIMENSION);
Surface* writeMatrix = new Surface(DIMENSION, DIMENSION);

void transition();
void transFuncCell( int, int );
void swap();

int main(int argc, char ** argv){
    readMatrix -> initializeSurface();

    readMatrix -> printSurfaceOnTerminal();
    writeMatrix -> printSurfaceOnTerminal();


    return 0;
}

void transition(){
    for( int i = 0; i < DIMENSION; i++ ){
        for( int j = 0; j < DIMENSION; j++ ){
            transFuncCell( i, j );
        }
    }

}


void swap(){
    Surface *p = readMatrix;
    readMatrix = writeMatrix;
    writeMatrix = p;
}


void transFuncCell( int i, int j){
    /*
        LEGGI DI EVOLUZIONE all'istante t
        
        Legge 1: se stato = 1 -> stato = 1
        (se sono aree cittadine, non bruceranno)

        Legge 2: se stato = 3 -> stato = 4
        (se sta bruciando, allora si spegnerà)

        Legge 3: se stato = 4 -> stato = 4
        (se è stato bruciato, non riceverà alcun cambiamento)

        Legge 4: se stato = 3 -> stati delle celle adiacenti = 3
        (se sta bruciando, potrebbe influire sulle celle adiacenti)
    
    */

    int cellState = readMatrix -> getCell(i, j).getState();

    /* - legge 1 e 3 - */
    if( cellState != 1 && cellState != 4 ){ //TODO - si suppone rimangano uguali
        /* - legge 2 - */
        if( cellState == 2 )
            readMatrix -> surface[V(i, readMatrix -> cols, j)].setState(2);
        if( cellState == 3 ){
            // TODO - Come influire sulle celle adiacenti???
            


        }

    }
    
}






