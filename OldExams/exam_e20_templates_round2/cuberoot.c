#include <math.h>
#include <stdio.h>

double geval(double x) { 
    double den = pow(((x*x)+2),2.0/3.0)+(pow(((x*x)+2),1.0/3.0)*pow((x*x),1.0/3.0))+pow(x*x,2.0/3.0);
    return 2.0/den;
}

int main(){
    double x = 2.0;
    double res = geval(x);
    printf("%f",res);
}
