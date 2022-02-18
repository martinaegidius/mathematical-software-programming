#include <math.h>

double feval(double x) { 
    /* Insert code here */
    if(sin(x)==0){
        return NAN;
    }
    else return -2*pow(sin(x/2.0),2)/sin(x);
}
