#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int size = 12;
    int field[1000][1000];
    int visitedPoints[1000][1000];

    int iPos = 0;
    int jPos = 0;
    
    int countVisitedPoints = 0;
    
    int countA = 0;
    int countB = 0;
    
    double m = 0;
    
    double probability = 0;
    
    srand ( time(NULL) );
    
    
    while(countA != (size * size)/4 || countB != (size * size)/4){
    
    double randNumber = 0;
    double fill = 0;
    countA = 0;
    countB = 0;
    
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            
            fill = (double)rand()/(double)RAND_MAX;
            randNumber = (double)rand()/(double)RAND_MAX;
            
            if(fill < 0.5) {
            if(randNumber < 0.5) {
                field[i][j] = 1; 
                countA++;
            }
            else if (randNumber > 0.5){
                field[i][j] = 2; 
                countB++;
                }
            }
            else {
                field[i][j] = 0; 
            }
        }
    }
    }
    
    countA = 0;
    countB = 0;
    
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            if(field[i][j] == 1) {
                countA++;
            } else if(field[i][j] == 2) {
                countB++;
            }
            /*printf("%d  ", field[i][j]);
            if(j==size-1){
            printf("\n");
            }*/
        }
    }
    
    //from there we have the filled field
    
    double countM = 0;
    
    
    for(int k = 0; k < 1000; k++) {
        
        
    //a meglátogatott pontok uresse tetele
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            visitedPoints[i][j] = 0;
        }
    }
    countVisitedPoints = 0;
    
    int aA = 0;
    int bB = 0;
    int aB = 0;
    int bA = 0;
        
    //oldalak kalkulasa
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            
            //up
            if(i == 0) {
            if(field[i][j] == 1) {
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i + 1][j - 1] == 1) aA++;
                if(field[i + 1][j - 1] == 2) aB++;
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                
                if(field[size - 1][j] == 1) aA++;
                if(field[size - 1][j] == 2) aB++;
                if(field[size - 1][j - 1] == 1) aA++;
                if(field[size - 1][j - 1] == 2) aB++;
                if(field[size - 1][j + 1] == 1) aA++;
                if(field[size - 1][j + 1] == 2) aB++;
                
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                if(field[i + 1][j + 1] == 1) aA++;
                if(field[i + 1][j + 1] == 2) aB++;
                }
            else if(field[i][j] == 2) {
                if(field[i + 1][j] == 2) bB++;
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j - 1] == 2) bB++;
                if(field[i + 1][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i][j - 1] == 1) bA++;
                
                if(field[size - 1][j] == 2) bB++;
                if(field[size - 1][j] == 1) bA++;
                if(field[size - 1][j - 1] == 2) bB++;
                if(field[size - 1][j - 1] == 1) bA++;
                if(field[size - 1][j + 1] == 2) bB++;
                if(field[size - 1][j + 1] == 1) bA++;
                
                if(field[i][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i + 1][j + 1] == 2) bB++;
                if(field[i + 1][j + 1] == 1) bA++;
                }
            } 
            //down
            else if(i == size - 1) {
            if(field[i][j] == 1) {
                if(field[0][j] == 1) aA++;
                if(field[0][j] == 2) aB++;
                if(field[0][j - 1] == 1) aA++;
                if(field[0][j - 1] == 2) aB++;
                if(field[0][j + 1] == 1) aA++;
                if(field[0][j + 1] == 2) aB++;
                
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                if(field[i - 1][j - 1] == 1) aA++;
                if(field[i - 1][j - 1] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                if(field[i - 1][j + 1] == 1) aA++;
                if(field[i - 1][j + 1] == 2) aB++;
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                }
            else if(field[i][j] == 2) {
                if(field[0][j] == 1) bA++;
                if(field[0][j] == 2) bB++;
                if(field[0][j - 1] == 1) bA++;
                if(field[0][j - 1] == 2) bB++;
                if(field[0][j + 1] == 1) bA++;
                if(field[0][j + 1] == 2) bB++;
                
                if(field[i][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i - 1][j - 1] == 1) bA++;
                if(field[i - 1][j - 1] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                if(field[i - 1][j + 1] == 1) bA++;
                if(field[i - 1][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                }
            }
            else if(j == 0) {
            if(field[i][j] == 1) {
                if(field[i][size - 1] == 1) aA++;
                if(field[i][size - 1] == 2) aB++;
                if(field[i - 1][size - 1] == 1) aA++;
                if(field[i - 1][size - 1] == 2) aB++;
                if(field[i + 1][size - 1] == 1) aA++;
                if(field[i + 1][size - 1] == 2) aB++;
                
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                if(field[i - 1][j + 1] == 1) aA++;
                if(field[i - 1][j + 1] == 2) aB++;
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                if(field[i + 1][j + 1] == 1) aA++;
                if(field[i + 1][j + 1] == 2) aB++;
                }
            if(field[i][j] == 2) {
                if(field[i][size - 1] == 1) bA++;
                if(field[i][size - 1] == 2) bB++;
                if(field[i - 1][size - 1] == 1) bA++;
                if(field[i - 1][size - 1] == 2) bB++;
                if(field[i + 1][size - 1] == 1) bA++;
                if(field[i + 1][size - 1] == 2) bB++;
                
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                if(field[i - 1][j + 1] == 1) bA++;
                if(field[i - 1][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                if(field[i + 1][j + 1] == 1) bA++;
                if(field[i + 1][j + 1] == 2) bB++;
            }
            } else if(j == size-1) {
            if(field[i][j] == 1) {
                if(field[i][0] == 1) aA++;
                if(field[i][0] == 2) aB++;
                if(field[i - 1][0] == 1) aA++;
                if(field[i - 1][0] == 2) aB++;
                if(field[i + 1][0] == 1) aA++;
                if(field[i + 1][0] == 2) aB++;
                
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i + 1][j - 1] == 1) aA++;
                if(field[i + 1][j - 1] == 2) aB++;
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                if(field[i - 1][j - 1] == 1) aA++;
                if(field[i - 1][j - 1] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                }
            if(field[i][j] == 2) {
                if(field[i][0] == 1) bA++;
                if(field[i][0] == 2) bB++;
                if(field[i - 1][0] == 1) bA++;
                if(field[i - 1][0] == 2) bB++;
                if(field[i + 1][0] == 1) bA++;
                if(field[i + 1][0] == 2) bB++;
                
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j] == 2) bB++;
                if(field[i + 1][j - 1] == 1) bA++;
                if(field[i + 1][j - 1] == 2) bB++;
                if(field[i][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i - 1][j - 1] == 1) bA++;
                if(field[i - 1][j - 1] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                }
            }
            //other
            else {
            if(field[i][j] == 1) {
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i + 1][j - 1] == 1) aA++;
                if(field[i + 1][j - 1] == 2) aB++;
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                if(field[i - 1][j - 1] == 1) aA++;
                if(field[i - 1][j - 1] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                if(field[i - 1][j + 1] == 1) aA++;
                if(field[i - 1][j + 1] == 2) aB++;
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                if(field[i + 1][j + 1] == 1) aA++;
                if(field[i + 1][j + 1] == 2) aB++;
            } else if(field[i][j] == 2) {
                if(field[i + 1][j] == 2) bB++;
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j - 1] == 2) bB++;
                if(field[i + 1][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i][j - 1] == 1) bA++;
                if(field[i - 1][j - 1] == 2) bB++;
                if(field[i - 1][j - 1] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j + 1] == 2) bB++;
                if(field[i - 1][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i + 1][j + 1] == 2) bB++;
                if(field[i + 1][j + 1] == 1) bA++;
            }
            }
        }
    }
   
    //oldal kompenzacio
    aA = aA / 2;
    bB = bB / 2;
    aB = aB / 2;
    bA = bA / 2;
    
    //printf("A-A: %d  \n", aA);
    //printf("B-B: %d  \n", bB);
    //printf("A-B: %d  \n", aB);
    //printf("B-A: %d  \n", bA);
    
    m = (double) (aA + bB)/(aA + aB + bA + bB);
    
    //printf("%f  \n", m);
    
    int i = 0;
    int j = 0;
    
    while(countVisitedPoints != (size * size) / 2){
    
    aA = 0;
    bB = 0;
    aB = 0;
    bA = 0;
    
    do{
    iPos = (rand() % (size - 1 + 1));
    jPos = (rand() % (size - 1 + 1));
    }while(field[iPos][jPos] < 1);
    
    //printf("A POZICIO [i: %d  ", iPos);
    //printf("j : %d  ]\n", jPos);
    
    i = iPos;
    j = jPos;
    
    aA = 0;
    bB = 0;
    aB = 0;
    bA = 0;
    
            //up
            if(i == 0) {
            if(field[i][j] == 1) {
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i + 1][j - 1] == 1) aA++;
                if(field[i + 1][j - 1] == 2) aB++;
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                
                if(field[size - 1][j] == 1) aA++;
                if(field[size - 1][j] == 2) aB++;
                if(field[size - 1][j - 1] == 1) aA++;
                if(field[size - 1][j - 1] == 2) aB++;
                if(field[size - 1][j + 1] == 1) aA++;
                if(field[size - 1][j + 1] == 2) aB++;
                
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                if(field[i + 1][j + 1] == 1) aA++;
                if(field[i + 1][j + 1] == 2) aB++;
                }
            else if(field[i][j] == 2) {
                if(field[i + 1][j] == 2) bB++;
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j - 1] == 2) bB++;
                if(field[i + 1][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i][j - 1] == 1) bA++;
                
                if(field[size - 1][j] == 2) bB++;
                if(field[size - 1][j] == 1) bA++;
                if(field[size - 1][j - 1] == 2) bB++;
                if(field[size - 1][j - 1] == 1) bA++;
                if(field[size - 1][j + 1] == 2) bB++;
                if(field[size - 1][j + 1] == 1) bA++;
                
                if(field[i][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i + 1][j + 1] == 2) bB++;
                if(field[i + 1][j + 1] == 1) bA++;
                }
            } 
            //down
            else if(i == size - 1) {
            if(field[i][j] == 1) {
                if(field[0][j] == 1) aA++;
                if(field[0][j] == 2) aB++;
                if(field[0][j - 1] == 1) aA++;
                if(field[0][j - 1] == 2) aB++;
                if(field[0][j + 1] == 1) aA++;
                if(field[0][j + 1] == 2) aB++;
                
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                if(field[i - 1][j - 1] == 1) aA++;
                if(field[i - 1][j - 1] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                if(field[i - 1][j + 1] == 1) aA++;
                if(field[i - 1][j + 1] == 2) aB++;
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                }
            else if(field[i][j] == 2) {
                if(field[0][j] == 1) bA++;
                if(field[0][j] == 2) bB++;
                if(field[0][j - 1] == 1) bA++;
                if(field[0][j - 1] == 2) bB++;
                if(field[0][j + 1] == 1) bA++;
                if(field[0][j + 1] == 2) bB++;
                
                if(field[i][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i - 1][j - 1] == 1) bA++;
                if(field[i - 1][j - 1] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                if(field[i - 1][j + 1] == 1) bA++;
                if(field[i - 1][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                }
            }
            else if(j == 0) {
            if(field[i][j] == 1) {
                if(field[i][size - 1] == 1) aA++;
                if(field[i][size - 1] == 2) aB++;
                if(field[i - 1][size - 1] == 1) aA++;
                if(field[i - 1][size - 1] == 2) aB++;
                if(field[i + 1][size - 1] == 1) aA++;
                if(field[i + 1][size - 1] == 2) aB++;
                
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                if(field[i - 1][j + 1] == 1) aA++;
                if(field[i - 1][j + 1] == 2) aB++;
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                if(field[i + 1][j + 1] == 1) aA++;
                if(field[i + 1][j + 1] == 2) aB++;
                }
            if(field[i][j] == 2) {
                if(field[i][size - 1] == 1) bA++;
                if(field[i][size - 1] == 2) bB++;
                if(field[i - 1][size - 1] == 1) bA++;
                if(field[i - 1][size - 1] == 2) bB++;
                if(field[i + 1][size - 1] == 1) bA++;
                if(field[i + 1][size - 1] == 2) bB++;
                
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                if(field[i - 1][j + 1] == 1) bA++;
                if(field[i - 1][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                if(field[i + 1][j + 1] == 1) bA++;
                if(field[i + 1][j + 1] == 2) bB++;
            }
            } else if(j == size-1) {
            if(field[i][j] == 1) {
                if(field[i][0] == 1) aA++;
                if(field[i][0] == 2) aB++;
                if(field[i - 1][0] == 1) aA++;
                if(field[i - 1][0] == 2) aB++;
                if(field[i + 1][0] == 1) aA++;
                if(field[i + 1][0] == 2) aB++;
                
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i + 1][j - 1] == 1) aA++;
                if(field[i + 1][j - 1] == 2) aB++;
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                if(field[i - 1][j - 1] == 1) aA++;
                if(field[i - 1][j - 1] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                }
            if(field[i][j] == 2) {
                if(field[i][0] == 1) bA++;
                if(field[i][0] == 2) bB++;
                if(field[i - 1][0] == 1) bA++;
                if(field[i - 1][0] == 2) bB++;
                if(field[i + 1][0] == 1) bA++;
                if(field[i + 1][0] == 2) bB++;
                
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j] == 2) bB++;
                if(field[i + 1][j - 1] == 1) bA++;
                if(field[i + 1][j - 1] == 2) bB++;
                if(field[i][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i - 1][j - 1] == 1) bA++;
                if(field[i - 1][j - 1] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                }
            }
            //other
            else {
            if(field[i][j] == 1) {
                if(field[i + 1][j] == 1) aA++;
                if(field[i + 1][j] == 2) aB++;
                if(field[i + 1][j - 1] == 1) aA++;
                if(field[i + 1][j - 1] == 2) aB++;
                if(field[i][j - 1] == 1) aA++;
                if(field[i][j - 1] == 2) aB++;
                if(field[i - 1][j - 1] == 1) aA++;
                if(field[i - 1][j - 1] == 2) aB++;
                if(field[i - 1][j] == 1) aA++;
                if(field[i - 1][j] == 2) aB++;
                if(field[i - 1][j + 1] == 1) aA++;
                if(field[i - 1][j + 1] == 2) aB++;
                if(field[i][j + 1] == 1) aA++;
                if(field[i][j + 1] == 2) aB++;
                if(field[i + 1][j + 1] == 1) aA++;
                if(field[i + 1][j + 1] == 2) aB++;
            } else if(field[i][j] == 2) {
                if(field[i + 1][j] == 2) bB++;
                if(field[i + 1][j] == 1) bA++;
                if(field[i + 1][j - 1] == 2) bB++;
                if(field[i + 1][j - 1] == 1) bA++;
                if(field[i][j - 1] == 2) bB++;
                if(field[i][j - 1] == 1) bA++;
                if(field[i - 1][j - 1] == 2) bB++;
                if(field[i - 1][j - 1] == 1) bA++;
                if(field[i - 1][j] == 2) bB++;
                if(field[i - 1][j] == 1) bA++;
                if(field[i - 1][j + 1] == 2) bB++;
                if(field[i - 1][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i][j + 1] == 2) bB++;
                if(field[i][j + 1] == 1) bA++;
                if(field[i + 1][j + 1] == 2) bB++;
                if(field[i + 1][j + 1] == 1) bA++;
            }
        }
    
    probability = 0.00025;
    double randNumber = 0;
    int r1 = 0;
    int r2 = 0;
    int canMove = 0;
    
    if(visitedPoints[iPos][jPos] == 0) {
        //ha nem a szelen vagyunk
        if(0 < iPos && iPos < (size-1) && 0 < jPos && jPos < (size-1)) {
            //ha valaki rosszul erzi magat
            if((aA + bB) <= (aB + bA)) {
                randNumber = (double)rand()/(double)RAND_MAX;
                if(randNumber < probability) {
                //ha nincs hova mennie mert mindenhol vannak    
                if((aA + bB + aB + bA) == 8) {
                    visitedPoints[iPos][jPos] = 2;
                    countVisitedPoints++;    
                } else {
                do{
                    r1 = rand() % 3;
                    r1 -= 1;
                    r2 = rand() % 3;
                    r2 -= 1;
                    if(field[iPos + r1][jPos + r2] == 0) {
                        field[iPos + r1][jPos + r2] = field[iPos][jPos];
                        field[iPos][jPos] = 0;
                        visitedPoints[iPos + r1][jPos + r2] = 3;
                        countVisitedPoints++;
                    }
                }while(field[iPos + r1][jPos + r2] == 0);
                }
                } else {
                    visitedPoints[iPos][jPos] = 2;
                    countVisitedPoints++;    
                }
            } 
            //ha valaki nem erzi magat rosszul
            else {
                visitedPoints[iPos][jPos] = 2;
                countVisitedPoints++;
            }
        }
        //ha a szelen vagyunk
        else {
/*if(iPos == 0 && jPos == 0) {
            //ha rosszul erzi magat
            if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r1 == 1 && r2 == -1) {
                            if(field[iPos + 1][jPos + (size-1)] == 0) {
                                field[iPos + 1][jPos + (size-1)] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + 1][jPos + (size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == -1) {
                            if(field[iPos][jPos + (size-1)] == 0) {
                                field[iPos][jPos + (size-1)] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos][jPos + (size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == -1) {
                            if(field[iPos + (size-1)][jPos + (size-1)] == 0) {
                                field[iPos + (size-1)][jPos + (size-1)] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + (size-1)][jPos + (size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 0) {
                            if(field[iPos + (size-1)][jPos] == 0) {
                                field[iPos + (size-1)][jPos] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + (size-1)][jPos] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 1) {
                            if(field[iPos + (size-1)][jPos + 1] == 0) {
                                field[iPos + (size-1)][jPos + 1] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + (size-1)][jPos + 1] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == 1) {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 1) {
                            if(field[iPos + r1][jPos + 1] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 0) {
                            if(field[iPos + r1][jPos + 1] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
            }*/
/*else if(iPos == 0 && jPos == (size-1)) {
            //ha rosszul erzi magat
            if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r1 == 1 && r2 == 1) {
                            if(field[iPos + 1][0] == 0) {
                                field[iPos + 1][0] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + 1][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == 1) {
                            if(field[iPos][0] == 0) {
                                field[iPos][0] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 1) {
                            if(field[iPos + (size-1)][0] == 0) {
                                field[iPos + (size-1)][0] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + (size-1)][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 0) {
                            if(field[iPos + (size-1)][jPos] == 0) {
                                field[iPos + (size-1)][jPos] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + (size-1)][jPos] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == -1) {
                            if(field[iPos + (size-1)][jPos - 1] == 0) {
                                field[iPos + (size-1)][jPos - 1] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + (size-1)][jPos + 1] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == -1) {
                            if(field[iPos + r1][jPos + 1] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == -1) {
                            if(field[iPos + r1][jPos + 1] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 0) {
                            if(field[iPos + r1][jPos + 1] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] == 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
            }
else if(iPos == (size-1) && jPos == 0) {
            //ha rosszul erzi magat
            if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r1 == 1 && r2 == -1) {
                            if(field[0][jPos + (size-1)] == 0) {
                                field[0][jPos + (size-1)] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][jPos + (size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == -1) {
                            if(field[iPos][jPos + (size-1)] == 0) {
                                field[iPos][jPos + (size-1)] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos][jPos + (size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == -1) {
                            if(field[iPos - 1][jPos + (size-1)] == 0) {
                                field[iPos - 1][jPos + (size-1)] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos - 1][jPos + (size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 0) {
                            if(field[iPos - 1][jPos] == 0) {
                                field[iPos - 1][jPos] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos - 1][jPos] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 1) {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == 1) {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 1) {
                            if(field[0][jPos + r2] == 0) {
                                field[0][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 0) {
                            if(field[0][jPos + r2] == 0) {
                                field[0][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
            }
else if(iPos == (size-1) && jPos == (size-1)) {
            //ha rosszul erzi magat
            if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r1 == 1 && r2 == -1) {
                            if(field[0][jPos + r2] == 0) {
                                field[0][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == -1) {
                            if(field[iPos][jPos + r2] == 0) {
                                field[iPos][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == -1) {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == -1 && r2 == 0) {
                            if(field[iPos + r1][jPos] == 0) {
                                field[iPos + r1][jPos] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos] = 1;
                                countVisitedPoints++;
                                canMove++;  
                            }
                        }
                        if(r1 == -1 && r2 == 1) {
                            if(field[iPos + r1][0] == 0) {
                                field[iPos + r1][0] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 0 && r2 == 1) {
                            if(field[iPos + r1][0] == 0) {
                                field[iPos + r1][0] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 1) {
                            if(field[0][0] == 0) {
                                field[0][0] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        if(r1 == 1 && r2 == 0) {
                            if(field[0][jPos + r2] == 0) {
                                field[0][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
            }*/
if(iPos == 0 && 0 < jPos && jPos < (size-1)) {
    if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r1 == -1) {
                            if(field[(size-1)][jPos + r2] == 0) {
                                field[(size-1)][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[(size-1)][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        else {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }    
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
}
else if(iPos == (size-1) && 0 < jPos && jPos < (size-1)) {
        if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r1 == 1) {
                            if(field[0][jPos + r2] == 0) {
                                field[0][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[0][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        else {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }    
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
}
else if(jPos == 0 && 0 < iPos && iPos < (size-1)) {
            if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r2 == -1) {
                            if(field[iPos + r1][(size-1)] == 0) {
                                field[iPos + r1][(size-1)] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][(size-1)] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        else {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }    
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
}
else if(jPos == (size-1) && 0 < iPos && iPos < (size-1)) {
                if((aA + bB + aB + bA) == 8) {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;               
            } else {
                    if((aA + bB) < (aB + bA)) {
                    randNumber = (double)rand()/(double)RAND_MAX;
                    //ha elmegy
                    if(randNumber < probability) {
                        do{
                        r1 = rand() % 3;
                        r1 -= 1;
                        r2 = rand() % 3;
                        r2 -= 1;
                        if(r2 == 1) {
                            if(field[iPos + r1][0] == 0) {
                                field[iPos + r1][0] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][0] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }
                        }
                        else {
                            if(field[iPos + r1][jPos + r2] == 0) {
                                field[iPos + r1][jPos + r2] = field[iPos][jPos];
                                field[iPos][jPos] = 0;
                                visitedPoints[iPos + r1][jPos + r2] = 1;
                                countVisitedPoints++;
                                canMove++;    
                            }    
                        }
                        }while(canMove != 1);
                    } 
                    //ha nem megy el
                    else {
                        visitedPoints[iPos][jPos] = 1;
                        countVisitedPoints++;
                    }
                }
                //ha nem erzi magat rosszul
                else {
                visitedPoints[iPos][jPos] = 1;
                countVisitedPoints++;
                }
            }
}
            else {
            visitedPoints[iPos][jPos] = 1;
            countVisitedPoints++;
            }
        }
        
        //printf("%d  \n", countVisitedPoints);
    }
    
    //printf("A-A: %d  \n", aA);
    //printf("B-B: %d  \n", bB);
    //printf("A-B: %d  \n", aB);
    //printf("B-A: %d  \n", bA);
    
    }
    
    /*for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            printf("%d  ", visitedPoints[i][j]);
            if(j==size-1){
            printf("\n");
            }
        }
    }*/
    
    //kiíratás
    countA = 0;
    countB = 0;
    
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            if(field[i][j] == 1) {
                countA++;
            } else if(field[i][j] == 2) {
                countB++;
            }
            /*printf("%d  ", field[i][j]);
            if(j==size-1){
            printf("\n");
            }*/
        }
    }
    
    if(k > 899){
    countM += m;
    }
    //printf("%d  \n", countA);
    //printf("%d \n", countB);
}

printf("%f \n", countM / 100);
}