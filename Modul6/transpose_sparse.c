#include <stdlib.h>
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


void coo_trans(coo_t *A) {
    /* Insert your code here */
    size_t shape_buffer = A->shape[0];
    A->shape[0] = A->shape[1]; //make rows columns 
    A->shape[1] = shape_buffer; //make columns = rows
    
    //size_t * tmp_pointer = (size_t *)malloc(A->nnz*sizeof(size_t));
    
    size_t * tmp_pointer;
    tmp_pointer = A->rowidx;
    A->rowidx = A->colidx;         
    A->colidx = tmp_pointer;
}
