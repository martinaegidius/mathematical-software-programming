#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dhhmv(int n, const double *u, double *x){
    double *uut = (double*)malloc(n*n*sizeof(double));
    double *J = (double*)malloc(n*n*sizeof(double));
    if(uut==NULL || J==NULL || n<2 || u==NULL || x==NULL){
        return -1; //sadly, an initialized pointer without value is undefined and cant be checked for.. It could evaluate to NULL, but often wont.
    }
    J[0] = 1.0;
    double den = u[0]*u[0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            uut[j+i*n] = u[i]*u[j];
            
            if(j==i && j>0){
                den -= uut[j+i*n];
                J[j+i*n] = -1;
            }    
            else if (j!=0 && i!=0 && i!=j){ //is enough with just j!=0
                J[j+i*n] = 0.0;
            }        
        }
    }
    den = 2/den;

    for(int i = 0;i<n*n;i++){
        J[i] -= den*uut[i];
    }


    for(int i=0;i<n;i++){
        double seqsum = 0.0;
        for(int j=0;j<n;j++){
            seqsum += x[j]*J[j+i*n];
        }
        J[i] = seqsum; //NEED TO HOLD VALS SOMEWHERE, MIGHT ASWELL OVERWRITE FIRST ROW
    }

    for(int i=0;i<n;i++){
        x[i] = J[i];
    }
    
    printf("Multiplication product Tx is: ");
    for(int i=0;i<n;i++){
        printf("%f, ",x[i]);
    }
    free(uut);
    free(J);
   
    return 0;
    
}


int main(){
    double u_val[2] = {2,3};
    double *u;
    u = u_val;
    double x_val[2] = {2,4};
    double *x;
    x = x_val;
    int n = 2;
    int outers = dhhmv(n,u,x);
    printf("\n Exit code: %d\n",outers);
    return 0;

    
}