#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define pi M_PI

int sphere_radius(double radi){
    double V = (4.0f/3.0f)*pi*(radi*radi*radi);
    printf("function value gives %f",V);
    return V;
}

int main(void){
    double inputR;
    printf("Please enter radius of sphere: ");
    scanf("%lf",&inputR);
    double result = sphere_radius(inputR);
    printf("\nResult is %E\n",result);
    return 0;

}