//
//  main.c
//  lab_13
//
//  Created by Александр on 3/22/19.
//  Copyright © 2019 Александр. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubblesort_increase(int *parr, int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (parr[j] > parr[j + 1]) {
                int buf = parr[j];
                parr[j] = parr[j + 1];
                parr[j + 1] = buf;
            }
        }
    }
}

void bubblesort_descending(int *parr, int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (parr[j] < parr[j + 1]) {
                int buf = parr[j];
                parr[j] = parr[j + 1];
                parr[j + 1] = buf;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int N = 0, M = 0;
    printf("size of arrA: ");
    scanf("%d", &N);
    printf("size of arrB: ");
    scanf("%d", &M);
    int *arrA = (int*)malloc(N * sizeof(int));
    int *arrB = (int*)malloc(M * sizeof(int));
    srand(time(0));
    
    for (int i = 0; i < N; ++i)
        arrA[i] = rand() % 10;
    
    for (int i = 0; i < M; ++i)
        arrB[i] = rand() % 10;
    
    bubblesort_increase(arrA, N);
    bubblesort_descending(arrB, M);
    
    printf("arrA: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", arrA[i]);
    printf("\n");
    
    printf("arrB: ");
    for (int i = 0; i < M; ++i)
        printf("%d ", arrB[i]);
    printf("\n");
    
    int K = M + N;
    
    int *arrC = (int*)malloc(K * sizeof(int));
    
    int n = 0;
    for (int i = 0; i < K / 2; i++) //слияние
    {
        arrC[n++] = arrA[i];
        arrC[n++] = arrB[i];
    }
    
    bubblesort_descending(arrC, K);
    
    printf("ArrC: ");
    for (int i = 0; i < K; i++)
        for(int j = i + 1; j < K; ++j)
            if(arrC[i] != arrC[j])
                printf("%d ", arrC[j]);
    printf("\n");
    return 0;
}
