#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Aron Nagy - USVGM7

int main()
{
    int field[1000][1000]; //the field

    int size = 20; //size of the "dancefloor"


    //set-up phase
    for(int i=0; i<=size+1; i++) {
        for(int j=0;j<=size+1;j++) {

        //setting up "people"
        field[i][j]=1;

        //setting up "walls"
        if(i == 0) {
            field[i][j]=2;
        } else if(i == size+1) {
            field[i][j]=2;
        } else if(j == 0) {
            field[i][j]=2;
        } else if(j == size+1) {
            field[i][j]=2;
        }

        //setting up "doors"
        //4x2 case
        /*field[0][size/2]=0;
        field[0][size/2+1]=0;

        field[size+1][size/2]=0;
        field[size+1][size/2+1]=0;

        field[size/2][0]=0;
        field[size/2+1][0]=0;

        field[size/2][size+1]=0;
        field[size/2+1][size+1]=0;*/

        //2x4 case
        /*field[0][size/2-1]=0;
        field[0][size/2]=0;
        field[0][size/2+1]=0;
        field[0][size/2+2]=0;

        field[size+1][size/2-1]=0;
        field[size+1][size/2]=0;
        field[size+1][size/2+1]=0;
        field[size+1][size/2+2]=0;*/

        //1x8 case
        field[0][size/2-3]=0;
        field[0][size/2-2]=0;
        field[0][size/2-1]=0;
        field[0][size/2]=0;
        field[0][size/2+1]=0;
        field[0][size/2+1]=0;
        field[0][size/2+1]=0;
        field[0][size/2+1]=0;

        //printout
        printf("%d  ", field[i][j]);
            if(j==size+1){
            printf("\n");
            }
      }
    }

    srand ( time(NULL) ); //random number generator

    int iPos = -1; //i position
    int jPos = -1; //j position
    int emptyPos = -1; //empty position
    int steps = 0; //number of steps what was necessary to make the danceclub empty


    while(emptyPos < size*size) { //while the whole dancefloor will be empty
    emptyPos = 0;

    do{ //select a position if it is not empty
    iPos = (rand() % (size - 1 + 1)) + 1;
    jPos = (rand() % (size - 1 + 1)) + 1;
    }while(field[iPos][jPos] == 0);

    int direction = (rand() % (4 - 1 + 1)) + 1;//generating an "down-left-up-right" direction

    if(direction == 1) { //direction 1: down
        if(field[iPos+1][jPos] == 0) { //if the down position empty
            field[iPos+1][jPos] = 1; //we swap 1-0
            field[iPos][jPos] = 0;
        }
    }
    else if(direction == 2) { //direction 1: left
        if (field[iPos][jPos-1] == 0) { //if the left position empty
            field[iPos][jPos-1] = 1;
            field[iPos][jPos] = 0;
        }
    }
    else if(direction == 3) { //direction 1: up
        if(field[iPos-1][jPos] == 0) { //if the up position empty
            field[iPos-1][jPos] = 1; //we swap 1-0
            field[iPos][jPos] = 0;
        }
    }
    else if(direction == 4) { //direction 1: right
        if(field[iPos][jPos+1] == 0) { //if the right position empty
            field[iPos][jPos+1] = 1; //we swap 1-0
            field[iPos][jPos] = 0;
        }
    }

    //search empty places of dancefloor
    for(int i=1; i<=size; i++) {
        for(int j=1;j<=size;j++) {
            if(field[i][j] == 0){ //if position empty
            emptyPos++; //increase the number of empty positions by 1
            }
            }
        }

    //making the doors "clear" again
    //4x2 case
    /*field[0][size/2]=0;
    field[0][size/2+1]=0;

    field[size+1][size/2]=0;
    field[size+1][size/2+1]=0;

    field[size/2][0]=0;
    field[size/2+1][0]=0;

    field[size/2][size+1]=0;
    field[size/2+1][size+1]=0;*/

    //2x4 case
    /*field[0][size/2-1]=0;
    field[0][size/2]=0;
    field[0][size/2+1]=0;
    field[0][size/2+2]=0;

    field[size+1][size/2-1]=0;
    field[size+1][size/2]=0;
    field[size+1][size/2+1]=0;
    field[size+1][size/2+2]=0;*/

    field[0][size/2-3]=0;
    field[0][size/2-2]=0;
    field[0][size/2-1]=0;
    field[0][size/2]=0;
    field[0][size/2+1]=0;
    field[0][size/2+2]=0;
    field[0][size/2+3]=0;
    field[0][size/2+4]=0;

    steps++; //increase the number of steps by 1

    }

    printf("\n");

    //printing out empty dancefloor
    for(int i=0; i<=size+1; i++) {
        for(int j=0;j<=size+1;j++) {
            printf("%d  ", field[i][j]);
            if(j==size+1){
            printf("\n");
            }
        }
    }

    printf("\n");
    printf("Steps: %d ", steps); //print out how many steps was necessary to make the dancefloor empty

    return 0;
}
