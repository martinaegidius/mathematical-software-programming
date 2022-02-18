#include <stdlib.h>
#include <stdio.h>
#define N 50
double *init_array(size_t n, double h) {
    double *p=malloc(n*sizeof(*p));
    if (p != NULL) {
        for (size_t i=0;i<n;i++)
            *(p++)=i*h;
        }
    return p;}
    
    int main(void) {double *p=init_array(N);if (p == NULL)return EXIT_FAILURE;for (size_t k=0;k<N;k++) printf("%3d %6g\n",k,p[k]);free(p);return 0;}