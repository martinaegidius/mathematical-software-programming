#include <stdlib.h>
#include "csp.h"

// enum cstype { CSC, CSR };
// typedef struct csp /* compressed sparse format (CSC/CSR) */
// {
//     size_t shape[2];
//     enum cstype csx;
//     size_t *ptr;
//     size_t *idx;
//     double *val;
// } csp_t;


/* Sparse matrix-vector product */
void csp_mv(
    const csp_t *A,
    const double *x,
    double *y)
{
    if(A==NULL && x==NULL && y==NULL) return;
    if(A&&x&&y){
        if (A->csx == CSC){

            //module for CSC multiplication
            size_t noCol = A->shape[1]; //number of columns
            size_t *p_tmp = A->ptr;
            size_t * idx = A->idx; 
            double *a = A->val; 
            for(size_t i=0;i<noCol;i++){
                for(size_t j = p_tmp[i];j<p_tmp[i+1];j++){
                    y[idx[j]] += a[j]*x[i];
                }
            }//denne her løkke beregner y0,y1,y2 kolonnevist. Det vil sige, at den beregner første kolonnevektor af produktet, og gør det for hver kolonne og lægger til
        }
        else {

            //module for CSR multiplication
            size_t noRow = A->shape[0]; //number of rows
            size_t *p_tmp = A->ptr;
            size_t * idx = A->idx; 
            double *a = A->val; 
            for(size_t i=0;i<noRow;i++){
                for(size_t j = p_tmp[i];j<p_tmp[i+1];j++){
                    y[i] += a[j]*x[idx[j]];
                }
            }//denne her løkke beregner rækkevist værdierne for y. Det vil sige at den regner produktet mellem rækkevektoren og søjlevektoren for at finde førstekoordinat
        }
    }
    return;
}
    
