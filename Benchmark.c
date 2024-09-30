#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mm_malloc.h>
#define SIZE 1024
#define LOOPS 1E6
#define CPU_CLK 3.2E9


float main(){
    double *z;
    double *a;
    double *x;
    double *y;
    long long i;
    long long j;
    double start;
    double end;
    // allocating memmory 
    z = (double *)_mm_malloc(SIZE *sizeof(double), 64);
    a = (double *)_mm_malloc(SIZE *sizeof(double), 64);
    x = (double *)_mm_malloc(SIZE *sizeof(double), 64);
    y = (double *)_mm_malloc(SIZE *sizeof(double), 64);

    // filling the arrays with random values
    for (i =0; i < (SIZE); i++ ){
        x[i] = (double)rand() % 100;
        y[i] = (double)rand() % 100;
        z[i] = (double)rand() % 100;
        a[i] = (double)rand() % 100;

    }
    
   start = omp_get_wtime();

   for (j = 0 ; j < 1000000;i++){
       for(i = 0; i < 1000;i++) {
        z[i] = (a[i] * x[i]) + y[i];
        }
   }

    end = omp_get_wtime();
    printf ("Elapsed Time %f", end-start);

}