#include <stdlib.h>

enum cstype { CSC, CSR };
typedef struct csp /* compressed sparse format (CSC/CSR) */
{
    size_t shape[2];
    enum cstype csx;
    size_t *ptr;
    size_t *idx;
    double *val;
} csp_t;


/* Sparse matrix-vector product */
void csp_trans(csp_t *A) {
    size_t tmp = A->shape[0];
    A->shape[0] = A->shape[1];
    A->shape[1] = tmp;
    A->csx = (A->csx == CSC? CSR:CSC);

    /* Insert your code here */
}

// int main(void){
//     size_t shape[2] = {2,2};
//     csp_t * array =(csp_t*)csp_alloc(const shape[2],const size_t 4,CSC);
// }