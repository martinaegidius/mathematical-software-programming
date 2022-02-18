#include <math.h>
#include <stdio.h>

double geval(double x) { 
    return cbrt(pow(x,2)+2)-cbrt(pow(x,2));
}

int main(){
    double x = 12.0, outers;
    outers = geval(x);
    printf("%f",outers);
}
