#include <math.h>
#include <stdio.h>
double feval(double x) {
    /* Insert your code here */
    if(x<=0.1&&x>=-0.1){
        double eval = (1.0/2.0)-((x*x)/(4.0*3.0*2.0));
        return eval;
    }
    else if (!(x)){
        double eval = 1/2;
        return eval;
    }

    else{
        double eval = (1-cos(x))/(x*x);
        if (isnan(eval)&&!isnan(x)){
            eval = 0.0;
        }
        return eval;
    }

}

int main(void){
    double x = ;
    double outers = feval(x);
    printf("%f",outers);
}

