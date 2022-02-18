#include <stdio.h>
#include <math.h>
double feval(double x) {
    if (x<=0.2 && x>=-0.2){
        return 2*sinh(x); //identity
    }
    else {
        return exp(x)-exp(-x);
    }
}