#include <stdio.h>

double linear_max(const double x, const double *a, const double *b, unsigned int n){
    if(!x||!b||n<=0){return -1;}
    double max = a[0]*x+b[0];
    double feval = max; 
    for(int i=1;i<n;i++){
        feval = a[i]*x+b[i];
        // if(feval>max){ //non ternary form
        //     max = feval;
        // }
        max = (feval>max)?feval:max; //ternary form 

        
    }

    return max;
}

int main(){
    double x = 2.0;
    double a_arr[4] = {1000,2,3,4};
    double * a = a_arr;
    double b_arr[4] = {17,700,40000,1000};
    double *b = b_arr;
    unsigned int n = 4;
    double out = linear_max(x,a,b,n);
    printf("%f",out);
}