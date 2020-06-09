#include <stdio.h>
#include <stdlib.h>

//Aron Nagy - USVGM7

int main()
{
    int successfullRoots = 0; //number of the succesfull roots in a set
    int n = 0; //a set
    double p = 0; //probablity (based on succesfull roots / n)

    srand ( time(NULL) ); //random generator

    for(int m= 0; m <1000; m++){
    int table[1000][1000]; //the given table where we search the path to down from top
    int f = 1; //the family of the given field
    double ro = 0.7; //the chance that we fill up a table
    int root = 0; //number of existing roots
    int startFamily [0]; //the starting family of a 1-point
    int tableSize = 50; //size of table
    int mustChangedFamily = 0; //family that must be changed because it was a sub-family
    int smallerNeigbour = 0; //0 if a point has no smaller neighbour. More than 0 if it has.
    for(int i=0; i<tableSize; i++) {
      for(int j=0;j<tableSize;j++) {
            double r = ((double) rand() / (RAND_MAX)); //generating the "points"
            if(r <= ro) {
                if(i > 0 && table[i-1][j] > 0) {
                    table[i][j] = table[i-1][j];
                }
                else if(j > 0 && table[i][j-1] > 0) {
                    table[i][j] = table[i][j-1];
                }
                else {
                    table[i][j] = f;
                    f++;
                }
            } else {
                table[i][j] = 0;
            }
            /*printf("%d  ", table[i][j]);
            if(j==tableSize-1){
            printf("\n");
            }*/
      }
    }

    printf("\n");

    for(int i=tableSize-1; i>=0; i--) {
      for(int j=tableSize-1; j>= 0;j--) {
        if(table[i][j+1] != 0 && table[i][j] > table[i][j+1]){
            mustChangedFamily = table[i][j];
            smallerNeigbour = table[i][j+1];
            for(int k=0; k<tableSize; k++){
                for(int l=0; l<tableSize; l++) {
                    if(table[k][l] == mustChangedFamily){
                        table[k][l] = smallerNeigbour;
                    }
                }
            }
            smallerNeigbour = 0;
        }
        else if(table[i][j] != 0 && table[i][j] < table[i][j+1]){
            mustChangedFamily = table[i][j+1];
            smallerNeigbour = table[i][j];
            for(int k=tableSize-1; k>=0; k--){
                for(int l=tableSize-1; l>= 0;l--) {
                    if(table[k][l] == mustChangedFamily){
                        table[k][l] = smallerNeigbour;
                    }
                }
            }
            smallerNeigbour = 0;
        }
      }
    }

    for(int i=0; i < tableSize; i++) {
        startFamily[i] = table[0][i];
        for(int j=0; j < tableSize; j++) {
            if(startFamily[j] != 0 && table[tableSize-1][i] == startFamily[j]) {;
                root++;
            }
        }
    }

    if(root > 0) {
    printf("root exsists");
    printf("\n");
    successfullRoots++;
    } else {
    printf("no root");
    printf("\n");
    }
    n++;
    }
    p = successfullRoots / n;
    printf("%d  /", successfullRoots);
    printf(" %d ", n);
}
