#include <stdio.h>
#include <stdlib.h> //for malloc

int main(){
    double xval[4] = {1,2,3,4};
    double * x = xval;
    double yval[4] = {7,6,5,2};
    double ** ptr;
    ptr = &x; 
    printf("%f",&ptr);

    return 0;
}