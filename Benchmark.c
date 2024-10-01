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
    double wtick; 

    wtick = omp_get_wtick();

    // allocating memmory 
    z = (double *)_mm_malloc(SIZE *sizeof(double), 64);
    a = (double *)_mm_malloc(SIZE *sizeof(double), 64);
    x = (double *)_mm_malloc(SIZE *sizeof(double), 64);
    y = (double *)_mm_malloc(SIZE *sizeof(double), 64);

    // filling the arrays with random values
    for (i =0; i < (SIZE); i++ ){
        x[i] =  (double)(1 + rand() % 100);
        y[i] = (double)(1 + rand() % 100);
        z[i] = (double)(1 + rand() % 100);
        a[i] = (double)(1 + rand() % 100);

    }
    
   start = omp_get_wtime();

   for (j = 0 ; j < 1000000;j++){
       for(i = 0; i < SIZE;i++) {
            z[i] = (a[i] * x[i]) + y[i];
        }
   }

    end = omp_get_wtime();
    printf ("Elapsed Time: %f\n",(double) end-start);

    _mm_free(x);
    _mm_free(y);
    _mm_free(z);
    _mm_free(a);

}