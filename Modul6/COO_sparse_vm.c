#include "coo.h"

// typedef struct coo /* coordinate sparse format (COO) */
// {
//     size_t shape[2];   // number of rows and columns
//     size_t nnz;        // number of nonzeros
//     size_t capacity;   // capacity (length of arrays)
//     size_t *rowidx;    // pointer to row index array
//     size_t *colidx;    // pointer to col. index array
//     double *val;       // pointer to values
// } coo_t;

/* Sparse matrix-vector product */
void coo_mv(
    const coo_t *A,
    const double *x,
    double *y)
{
    /* Insert your code here */
    if(A&&x&&y){
        for (size_t i=0;i<A->nnz;i++){
            y[A->rowidx[i]] += A->val[i]*x[A->colidx[i]];
        }
    }
    

    

}

