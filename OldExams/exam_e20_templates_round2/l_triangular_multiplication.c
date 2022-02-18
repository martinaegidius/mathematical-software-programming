#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int darmv(int n, double * a, double * b, double * x) {
    /* Insert code here */
    // double * tmp_holder = (double*)calloc(n*sizeof(double));
    if(n<1||!a||!b||!x){
        return -1;
    }
    
    else{
        for(int i=0;i<n;i++){
            if(isnan(a[i])||isnan(b[i])||isnan(x[i])){return -1;}
        }
        double seqsum = 0.0;
        for(int i=0;i<n;i++){
            if(i<n-1){
                seqsum += b[i]*x[i]; //calculating last element of x
                // printf("\n %f\n",seqsum);
            }
            else{
                x[i] = seqsum+a[i]*x[i];
                // printf("last element triggered, %f",x[i]);
            }
        }
        for(int i=0;i<n-1;i++){
            x[i] = a[i]*x[i];
        }
        
        // //printing module
        // printf("\nX now is:\n");
        // for(int i=0;i<n;i++){
        //     printf("%f, ",x[i]);
        // }
        return 0;
    }
    
}

int main(){
    int n = 3;
    double x_arr[3] = {1,2.0,3.0};
    double a_arr[3] = {4,2,20};
    double b_arr[2] = {NAN,19};
    double * x = x_arr;
    double * a = a_arr;
    double * b = b_arr;
    int out = darmv(n,a,b,x);
    printf("\nExit code %d",out);
    return 0;
}