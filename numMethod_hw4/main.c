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
    double result[MAX_N];
    
    int n = 3;
    
    //set matrixA
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n+1); j++) {
            scanf("%lf", &matrixA[i][j]);
        }
    }
    
    //print result
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n+1); j++) {
            printf("%lf ", matrixA[i][j]);
        }
        puts("");
    }
    printf("\n");
    
    //gaussion elimination
    for(int j = 1; j <= n-1; j++) {
        for(int i = 1; i <= n; i++) {
            if(i > j) {
                double coeff = matrixA[i][j]/matrixA[j][j];
                for(int k = 1; k <= n+1; k++) {
                    matrixA[i][k] = matrixA[i][k]-(coeff*matrixA[j][k]);
                }
            }
        }
    }
    
    //print result
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= (n+1); j++) {
            printf("%lf ", matrixA[i][j]);
        }
        puts("");
    }
    
    //backwards substitution
    
    
    return 0;
}


