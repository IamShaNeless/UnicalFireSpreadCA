#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "surface.h"

#define STEPS 26
#define DIMENSION 40
#define DELTA 0.5

using namespace std;

Surface* readMatrix = new Surface(DIMENSION, DIMENSION);
Surface* writeMatrix = new Surface(DIMENSION, DIMENSION);

void transition();
void transFuncCell( int, int );
void swap();
bool fireProbability();

int main(int argc, char ** argv){
    srand (time(NULL));

    readMatrix -> debugInitializeSurface();
    writeMatrix -> debugInitializeSurface();

    for( int step = 0; step < STEPS; step++ ){
        system("clear");
        readMatrix -> printSurfaceOnTerminal();

        transition();
        swap();

        sleep(DELTA);
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
        case 4:
            writeMatrix -> surface[V(i, writeMatrix -> cols, j)].setState(4);
            break;
        case 3:
            /* - legge 4 - */
            for( int d_i = -1; d_i < 2; d_i++ ){
                for( int d_j = -1; d_j < 2; d_j++ ){

                    if( (d_i != 0 || d_j != 0)  && readMatrix -> surface[V(i + d_i, DIMENSION ,j + d_j)].getState() == 2){
                        if(fireProbability())
                            writeMatrix -> surface[V(i + d_i, DIMENSION ,j + d_j)].setState(3);
                    }
                }
            }

            /* - legge 2 - */
            writeMatrix -> surface[V(i, writeMatrix -> cols, j)].setState(4);
            break;
    }

}

bool fireProbability(){
    /* funzione per esprimere la probabilità di una cella allo stato 2
    di passare allo stato 3. Tale probabilità dipende, secondo la relazione di L.R,
    da svariati fattori:
    - tipo di vegetazione (non ancora implementato)
    - densità di vegetazione (non ancora implementato)
    - inclinazione del terreno (non implementato)
    - velocità del vento (che trascureremo)
    
    Per il momento, la probabilità sarà del 25% */
    return (rand() % 101 <= 25 );
}






