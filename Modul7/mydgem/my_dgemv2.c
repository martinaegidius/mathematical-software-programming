#include "my_dgemv_v2.h"
#include <stdio.h>


int my_dgemv_v2(
    double alpha,
    double beta,
    const array2d_t *A,
    const array_t *x,
    array_t *y
){
    if(!A||!x||!y||x->len!=A->shape[1]||y->len!=A->shape[0]){return 1;} //same as before
    else if(A->order == RowMajor){
        for (int i=0;i<A->shape[0];i++){
            y->val[i]*=beta;
        }
        for(int i = 0;i<A->shape[1];i++){//column by column (assignment text) Outer loop for sum of Ax 
            for(int j=0;j<A->shape[0];j++){
                y->val[j] += (x->val[i])*A->val[i+j*A->shape[1]]*alpha;
            }
        }   
    }
    else if(A->order == ColMajor){
         for (int i=0;i<A->shape[0];i++){
            y->val[i]*=beta;
            
        }
        for(int j=0;j<A->shape[1];j++){//row-sum 
            for(int i = 0;i<A->shape[0];i++){
                y->val[i] += alpha*(A->val[i+j*A->shape[0]])*x->val[j];
            }    
        }
    }
    return 0;
    
}
int main(void){
    //allocating + filling matrix
    array2d_t * A = (array2d_t*)malloc(12*sizeof(double));
    //testvector rowmajor
    // double avals[12] = {1,2,3,4,5,6,1,2,3,5,6,1};
    // A->order = RowMajor;
    //testvector columnmajor 
    double avals[12] = {1,4,1,5,2,5,2,6,3,6,3,1};
    A->order = ColMajor;

    A->val = avals; 
    A->shape[0] = 4;
    A->shape[1] = 3;
   

    //allocating + filling x and y
    array_t * x = (array_t*)malloc(3*sizeof(double));
    array_t * y = (array_t*)malloc(4*sizeof(double));
    double xval[3] = {1,2,3};
    double yval[4] = {3,4,5,7};
    x->val = xval; 
    y->val = yval; 
    x->len = 3;
    y->len = 4;
    double alpha = 2.0;
    double beta = 13;
    int outers = my_dgemv_v2(alpha,beta,A,x,y);
    printf("%d",outers);


    //printing module vector Y
    printf("\n--------------output y:\n");
    for(int i=0;i<y->len;i++){
        printf("%f, ",y->val[i]);
    }
    //printing module matrix A
    for(int i=0;i<A->shape[1];i++){
        printf("\n");
        for(int j=0;j<A->shape[0];j++){
            printf("%f, ",A->val[j+i*A->shape[0]]);
        }
    }

    
    return 0;
        
}