#ifndef SURFACE_H_
#define SURFACE_H_
#include <stdlib.h>
#include "cell.h"

#define V(R,COLS,C) ((R) * (COLS) + (C) )

class Surface{
    public:
        Cell *surface;
        int rows;
        int cols;
    
        Surface(int r, int c):rows(r), cols(c){
            surface = new Cell[r * c];
        }

        inline Cell getCell(int r, int c) { return this -> surface[V(r, this -> cols, c)]; }
        
        void printSurfaceOnTerminal(){
            for( int i = 0; i < rows; i++ ){
                for( int j = 0; j < cols; j++ ){
                    if( getCell(i, j).getState() == 4 )
                        printf(" - ");
                    else
                        printf( " %d " ,getCell(i, j).getState() );
                }
                printf("\n");
            }
        }

        void initializeSurface(){
            for( int i = 0; i < rows; i++ ){
                for( int j = 0; j < cols; j++ )
                    if( i == 0 || i == rows -1 || j == 0 || j == cols -1  )
                        this -> surface[V( i, this -> cols, j )].setState( 1 );
                    else
                        this -> surface[V( i, this -> cols, j )].setState( rand() % 4 + 1 );
            }
        }

        void nullifieSurface(){
            for( int i = 0; i < rows; i++ ){
                for( int j = 0; j < cols; j++ ){
                    this -> surface[V( i, this -> cols, j )].setState(1);
                }
            }
        }

        void debugInitializeSurface(){
            for( int i = 0; i < rows; i++ ){
                for( int j = 0; j < cols; j++ )
                    if( i == 0 || i == rows -1 || j == 0 || j == cols -1  )
                        this -> surface[V( i, this -> cols, j )].setState( 1 );
                    else
                        this -> surface[V( i, this -> cols, j )].setState( 2 );
            }

            int i = rows / 2;
            int j = cols / 2;
            this -> surface[V( i, this -> cols, j )].setState( 3 );
        }

};

#endif
