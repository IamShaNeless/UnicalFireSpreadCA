#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NCOLS 20
#define NROWS 20


/*
    Essendo un vettore unidimensionale, l'accesso alla cella è del tipo:
    se v[2][3]
    allora v[ 2 * ncols + 3 ]

    Allora gestiremo una macro, tale per cui v[2][3] = v[ 2 * ncols + 3 ] = MACRO(2,3)
*/
#define V(R, C) ((R) * NCOLS + (C))


int *readMatrix = new int[NROWS * NCOLS];
int *writeMatrix = new int[NROWS * NCOLS];
int nStep = 100;

void transFuncCell( int i, int j ){
    int count = 0;
    for( int d_i = -1; d_i < 2; d_i++  ){
        for( int d_j = -1; d_j < 2; d_j++ ){
            if( (d_i != 0 || d_j != 0)  && readMatrix[V( (i+d_i + NROWS) % NROWS, (j+d_j+NCOLS) % NCOLS )])

            count++;
        }
    }

    if( readMatrix[ V(i,j) ] == 1 ){
        if((count == 2 || count == 3) && readMatrix[ V(i,j) ] == 1)
            writeMatrix[ V(i,j) ] = 1;
        else
            writeMatrix[ V(i,j) ] = 0;            
    }
    else{
        if( count == 3 )
            writeMatrix[V(i,j)] = 1;
        else
            writeMatrix[V(i,j)] = 0;
    }
}

void transition(){
    for( int i = 0; i < NROWS; i++ ){
        for( int j = 0; j < NCOLS; j++ ){
            transFuncCell( i, j );
        }
    }
}

void init(){
    /* inizializzazione della readMatrix - tutte le celle morte */
    for(int i = 0; i < NROWS; i++)
        for(int j = 0; j < NCOLS; j++)
            readMatrix[V(i, j)] = rand() % 2;        
    
    
    /* Inizializziamo un glider al centro della matrice 
            *
              *
          * * *
    */
    /*
    int I = NROWS / 2;
    int J = NCOLS / 2;
    readMatrix[V(I - 1, J)] = 1;
    readMatrix[V(I + 1, J)] = 1;
    readMatrix[V(I, J+1)] = 1;
    readMatrix[V(I+1,J-1)] = 1;
    readMatrix[V(I+1,J+1)] = 1;
    */
    
}

void print(int step){
    printf("step %d\n", step);
    for(int i = 0; i < NROWS; i++){
        for(int j = 0; j < NCOLS; j++){
            if( readMatrix[V(i,j)] == 1 )
                printf(" * ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

void swap(){
    int *p = readMatrix;
    readMatrix = writeMatrix;
    writeMatrix = p;
}


int main( int argc, char** argv ){
    int rank, size;


    init();
    
    for( int step = 0; step < nStep; step++ ){
        system("clear");
        
        print(step);
        transition();       
        swap();

        sleep(1);
    }


    delete [] readMatrix;
    delete [] writeMatrix;


    return 0;
}