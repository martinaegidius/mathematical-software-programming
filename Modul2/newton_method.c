#include <math.h>
#include <stdio.h>

double ynew;

double newton_method(double x){
    double yold = 1; //startguess
    ynew = (yold+(x/yold))/2;
    while(fabs(yold-ynew)>=fabs(yold)*0.00001){
        yold = ynew; 
        ynew = (yold+(x/yold))/2;
    }
    return ynew;
}

int main(){
    double x;
    printf("Please enter a positive number: ");
    scanf("%lf",&x);
    double root = newton_method(x);
    printf("2. Found square root: %f\n",root);
    return 0;
}

