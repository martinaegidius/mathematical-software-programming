#include <math.h>
#include <stdio.h>

double feval(double x) { 
    if(sin(x)==0){ 
        return 0;
    }
    else{
        return 2*pow(sin(x/2),2)/sin(x);
    } 
}

int main(void){
    double x = 0.0;
    double outers = feval(x);
    printf("%f",outers);
    return 0;
}
// #include <stdio.h>
// #include <math.h>

// #define PI 3.14159265

// int main () {
//    double x, ret, val;

//    x = 45.0;
//    val = PI / 180;
//    ret = sin(x*val);
//    printf("The sine of %lf is %lf degrees", x, ret);
   
//    return(0);
// }
