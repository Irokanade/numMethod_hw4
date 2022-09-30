//
//  main.c
//  numMethod_hw4
//
//  Created by Michael Leong on 30/09/2022.
//

#include <stdio.h>
#define MAX_N 100


int main(int argc, const char * argv[]) {
    
    double matrixA[MAX_N][MAX_N];
    double vectorB[MAX_N];
    double result[MAX_N] = {1};
    double matrixL[MAX_N][MAX_N] = {0};
    
    int n = 4;
    
    //init matrixL
    for(int i = 1; i <= n; i++) {
        matrixL[i][i] = 1;
    }
    
    //set matrixA
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n); j++) {
            scanf("%lf", &matrixA[i][j]);
        }
        scanf("%lf", &vectorB[i]);
    }
    
    //print result
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n); j++) {
            printf("%lf ", matrixA[i][j]);
        }
        printf("| %lf\n", vectorB[i]);
        //puts("");
    }
    printf("\n");
    
    //gaussion elimination
    for(int j = 1; j <= n-1; j++) {
        for(int i = 1; i <= n; i++) {
            if(i > j) {
                double coeff = matrixA[i][j]/matrixA[j][j];
                //printf("coeff: %lf\n", coeff);
                //printf("j: %d, i: %i\n", j, i);
                matrixL[i][j] = coeff;
                for(int k = 1; k <= n; k++) {
                    matrixA[i][k] = matrixA[i][k]-(coeff*matrixA[j][k]);
                }
                vectorB[i] = vectorB[i]-(coeff*vectorB[j]);
            }
        }
    }
    
    printf("matrixU\n");
    //print result
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n); j++) {
            printf("%lf ", matrixA[i][j]);
        }
        printf("| %lf\n", vectorB[i]);
        //puts("");
    }
    printf("\n");
    
    //backwards substitution
    for(int i = n; i >= 1; i--) {
        for(int j = i+1; j <= n; j++) {
            vectorB[i] = vectorB[i] - matrixA[i][j]*result[j];
        }
        result[i] = vectorB[i]/matrixA[i][i];
    }
    
    printf("result\n");
    //print result
    for(int i = 1; i <= n; i++) {
        printf("%lf ", result[i]);
    }
    puts("");
    
    printf("matrixL\n");
    //print matrixL
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n); j++) {
            printf("%lf ", matrixL[i][j]);
        }
        puts("");
    }
    printf("\n");
    
    
    
    return 0;
}


