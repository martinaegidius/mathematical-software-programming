#include <math.h>
#include <stdio.h>


double two_pass(double * x,int length){
    double x_bar,v,ssum;
    ssum = 0.0;
    for(int i=0;i<length;i++){
        ssum += x[i];
    }
    x_bar = ssum/length;
    for(int i=0;i<length;i++){
        v += pow((x[i]-x_bar),2);
    }
    v = (1.0/(length-1.0))*v;
    printf("v in two_pass has become: %f",v);
    return v;
}

double one_pass(double * x,int length){
    double xk2,xk,v;
    xk = 0.0;
    xk2 = 0.0;
    for(int i=0;i<length;i++){
        xk += x[i];
        xk2 += pow(x[i],2);
    }
    v = (1.0/(length-1.0))*xk2-(length/(length-1.0))*pow((xk/length),2);
    printf("\nv in one_pass has become: %f",v);
    return v;
}

int main(void){
    int length = 5;
    double x_arr[5] = {25924.12,25924.15,25923.98,25924.19,25923.89};
    double *x = x_arr;
    double twopass = two_pass(x,length);
    double onepass = one_pass(x,length);
    return 0;  

}