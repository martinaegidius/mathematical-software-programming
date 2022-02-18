#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 16777216
extern int datasize1(int);
double arr[MAX_SIZE];

int datasize1(int elem) {
    for (int i=0; i<elem; i++) arr[i] *= 3;
    return(elem);
}

int main(void){
    int n = 20;
    clock_t t1,t2;
    t1 = clock();

    for(int i=0;i<n;i++){
        int output = datasize1(*arr);
    }
    t2 = clock()-t1;
    
    double avg = (((double)t2)/n)/CLOCKS_PER_SEC;
    printf("Average time: %g",avg);

    //in FLOPS instead: 
    //m = number of float-ops. in thus function there is one one floating point operation per 
    //loop element in datasize1. Number of operations thus m*MAX_SIZE*n. Thus:
    double flops = 1*MAX_SIZE*n/avg;
    printf("\nAverage FLOPS: %g",flops);



    return EXIT_SUCCESS;

}