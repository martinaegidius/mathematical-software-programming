#include <stdio.h>

double inner_product(const double *a, const double *b, int n){
    double sum = 0.0,*pa=a,*pb=b;
    while(pa<a+n){
        sum += *(pa++) * *(pb++);
        //is the same as writing 
        //sum += (*pa) * (*pb);
        // pa++;
        // pb++;
    }
    return sum;
}

int main(){
    double a_arr[4] = {1,2,3,4},*a,b_arr[4] = {1,1,1,1},*b;
    a = a_arr;
    b = b_arr;
    int n = 4;
    double result = inner_product(a,b,n);
    printf("%f",result);
    return 0;
}