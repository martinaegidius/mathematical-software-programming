#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	unsigned int n;
	double *coef;
} poly_t;


double poly_eval(poly_t *p, double x) {
    if(!p||!(p->coef)){return NAN;}
    double val; 
    val = p->coef[p->n];
    for(int i=1;i<=p->n;i++){
        val *= x; 
        val += p->coef[p->n-i];
    }
    return val;
}

int main(){
    int n = 3;
    double a[4] = {2,0.1,-2.0,0.2};
    double x=0.0;
    double *coef = a;
    poly_t *p = (poly_t*)malloc(n*sizeof(poly_t));
    p->n = n;
    p->coef = coef;
    double output =  poly_eval(p,x);
    printf("\n output becomes %f\n",output);
    return 0;
}