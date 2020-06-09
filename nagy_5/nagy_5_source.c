#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    double temperature = -0.5;
    
for(int i = 0; i < 50; i++) {
    temperature += 0.5;
    int countVisitedPoints = 0;
    
    int size = 10;
    int field[1000][1000];
    int visitedPoints[1000][1000];
    
    int nPlus = 0;
    int nMinus = 0;
    
    double orderParameter = 0;
    
    int iPos = 0;
    int jPos = 0;
    
    int deltaE = 0;
    
    double probability = 0;
    double turn = 0;
    
    double sum = 0;
    
    srand ( time(NULL) );
    
    //a meglátogatott pontok
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            visitedPoints[i][j] = 0;
        }
    }
    
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            //a mágnes negatív alja
            if(i < size/2) {
                field[i][j] = 1;
            }
            //rend paraméter számítása
            if(field[i][j] == 1) {
                nPlus++;
            } else nMinus++;
            //kiíratás
            /*printf("%d  ", field[i][j]);
            if(j==size-1){
            printf("\n");
            }*/
        }
    }
    
    //printf("%d\n", nPlus);
    //printf("%d\n", nMinus);

for(int i = 0; i <5000; i++)    
{
    
    do {
    
    nPlus = 0;
    nMinus = 0;
        
    int deepness = 0;
    int switchedDeepness = 0;

    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            //rend paraméter számítása
            if(field[i][j] == 1) {
                nPlus++;
            } else nMinus++;
        }
    }
    //printf("%d\n", nPlus);
    //printf("%d\n", nMinus);
    
    orderParameter = (double) abs(nPlus - nMinus) / (size * size);
    //printf("M = %f\n", orderParameter);
        
    iPos = (rand() % (size -1 + 1));
    jPos = (rand() % (size -1 + 1));
    
    turn = (double)rand()/(double)RAND_MAX;
    
    if(visitedPoints[iPos][jPos] == 0) {
        visitedPoints[iPos][jPos] = 1;
        countVisitedPoints++;
    }
    
    //printf("i = %d\n", iPos);
    //printf("j = %d\n", jPos);
    
    //ha valamelyik szélén vagyunk
    if(iPos == 0) {
        iPos = size - 1;
    }
    else if(iPos == size - 1) {
        iPos = 0;
    }
    
    if(jPos == 0) {
        jPos = size - 1;
    } else if(jPos == size - 1) {
        jPos = 0;
    }
    
    if(field[iPos-1][jPos] == field[iPos][jPos]) {
        deepness -= 1;
        switchedDeepness += 1;
    } else {
        deepness += 1;
        switchedDeepness -= 1;
    }
    if(field[iPos][jPos-1] == field[iPos][jPos]) {
        deepness -= 1;
        switchedDeepness += 1;
    } else {
        deepness += 1;
        switchedDeepness -= 1;
    }
    if(field[iPos][jPos+1] == field[iPos][jPos]) {
        deepness -= 1;
        switchedDeepness += 1;
    } else {
        deepness += 1;
        switchedDeepness -= 1;
    }
    if(field[iPos+1][jPos] == field[iPos][jPos]) {
        deepness -= 1;
        switchedDeepness += 1;
    } else {
        deepness += 1;
        switchedDeepness -= 1;
    }
    
    //printf("Deepness = %d ", deepness);
    //printf("Switched deepness = %d \n", switchedDeepness);
    
    deltaE = switchedDeepness - deepness;
    
    //printf("delta E = %d\n", deltaE);
    
    probability = 1 / (1 + exp(deltaE / temperature));
    
    //printf("Probability = %f\n", probability);
    //printf("Turn? = %f\n", turn);
    
    if(field[iPos][jPos] == 0) {
        if(turn < probability) {
            field[iPos][jPos] = 1;
        }
    } else {
        if(turn < probability) {
            field[iPos][jPos] = 0;
        }
    }
    
    } while(countVisitedPoints != size * size);
    //printf("%f\n", orderParameter);
    if(i > 3999) { sum += orderParameter; }
}
printf("%f\n", sum / 1000);
}
}
