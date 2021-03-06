#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "surface.h"

#define STEPS 26
#define DIMENSION 30
#define TIME_STEP 0.5

using namespace std;

Surface* readMatrix = new Surface(DIMENSION, DIMENSION);
Surface* writeMatrix = new Surface(DIMENSION, DIMENSION);

void transition();
void transFuncCell( int, int );
void swap();


int main(int argc, char ** argv){
    srand (time(NULL));

    readMatrix -> debugInitializeSurface();
    writeMatrix -> debugInitializeSurface();

    for( int step = 0; step < STEPS; step++ ){
        system("clear");
        readMatrix -> printSurfaceOnTerminal();

        transition();
        swap();

        sleep(TIME_STEP);
    }


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

    switch (cellState){
        case 1:
            writeMatrix -> surface[V(i, writeMatrix -> cols, j)].setState(1);
            break;
        case 3:
            writeMatrix -> surface[V(i, writeMatrix -> cols, j)].setState(4);
            break;
        case 2:
            /* - legge 4 - */
            int count = 0;
            for( int d_i = -1; d_i < 2; d_i++ ){
                for( int d_j = -1; d_j < 2; d_j++ ){
                    if( (d_i != 0 || d_j != 0)  && readMatrix -> surface[V(i + d_i, DIMENSION ,j + d_j)].getState() == 3){
                        count += 1;
                    }
                }
            }
            if( rand() % 8 + 1 <= count )
                readMatrix -> surface[V(i, DIMENSION, j)].setState(3);
            break;
    }

}








