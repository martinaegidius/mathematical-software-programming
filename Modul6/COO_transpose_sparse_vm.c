#include <stdlib.h>
//#include "coo.h"
typedef struct coo /* coordinate sparse format (COO) */
{
    size_t shape[2];   // number of rows and columns
    size_t nnz;        // number of nonzeros
    size_t capacity;   // capacity (length of arrays)
    size_t *rowidx;    // pointer to row index array
    size_t *colidx;    // pointer to col. index array
    double *val;       // pointer to values
} coo_t;


/* Sparse matrix-vector product */
void coo_mv_trans(
    const coo_t *A,
    const double *x,
    double *y)
{
    if(A&&x&&y){
        //first creating copy of A and transposing
        size_t * tmp_col = A->rowidx;
        size_t * tmp_row = A->colidx;
        for(size_t i=0;i<=A->nnz;i++){
            y[tmp_row[i]] += A->val[i]*x[tmp_col[i]];   
        }
    
    }
    return;
    
    /* Insert your code here */
}
// int main(){
//     return 0;
// }
