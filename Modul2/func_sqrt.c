#include <stdio.h>
#include <math.h>

double feval(double x){
if (x>1){
    double eval = fabs(x)*sqrt(1+(1.0/x)*(1.0/x))-1;
    return eval;
}

else if (x>=-0.1 && x<=0.1){
    double eval = (x*x)/(sqrt((x*x)+1)+1);
    return eval;
}
else {
    double y = 1.0;
    double eval = hypot(x,y)-1;
    return eval; 
}
}

        


int main(void){
    double x = 0.0
    double output = feval(x);
    printf("output has become %17.e\n",output);
    return output;
}