#include <math.h>
//#include <stdio.h>


double softplus(double x) {
    if(x>=15){
        return x;
    }
    else if (x<15){
        //double gert = log1p(exp(x));
        //printf("this loop baby %f\n",gert);
        return log1p(exp(x));
    }
}


int main(void){
    double x = 0;
    double eval = softplus(x);
    printf("eval is %f",eval);
    return 0;
}