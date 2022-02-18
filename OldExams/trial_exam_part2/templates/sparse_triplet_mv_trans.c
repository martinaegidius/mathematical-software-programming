#include "sparse_triplet.h"
#include <stdlib.h>
#include <stdio.h>

void sparse_triplet_mv_trans(
    const struct sparse_triplet *A,
    const double *x,
    double *y) {
        //module 1 for transposing COO cordinate format 
        size_t *rowIdx,*colIdx,m,n;
        rowIdx = A->J;
        colIdx = A->I;
        n = A->n;
        m = A->m;
        //transposing finished
        //multiplication module 
        double * y_val = (double*)malloc(n*sizeof(double)); 
        for(size_t i = 0;i<A->nnz;i++){
                y[rowIdx[i]] += A->V[i]*x[colIdx[i]];
            }
        //printing module
        for(size_t i=0;i<A->n;i++){
            printf("%f, ",y[i]);
        }    
    }
        



//for debugging 
int main(){
    double A[3]={2,3,5};
    size_t nnz = 3;
    struct sparse_triplet *arr = (struct sparse_triplet *)malloc(nnz*sizeof(struct sparse_triplet));
    arr->V = A;
    size_t m = 2,n=3;
    size_t rower[3] = {0,1,1};
    size_t columna[3] = {1,0,2};
    arr->m = m;
    arr->n = n;
    arr->nnz = nnz;
    arr->I = rower;
    arr->J = columna;

    double x_val[2] = {1,2};
    double y_val[3] = {9,3,3};
    double *x, *y;
    x = x_val;
    y = y_val;
    sparse_triplet_mv_trans(arr,x,y);
    

    return 0;
}
