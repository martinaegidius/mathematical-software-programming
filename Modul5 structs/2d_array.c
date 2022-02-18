#include <stdlib.h>
#include <stdio.h>

typedef struct array { 
    size_t len;       // length of array
    size_t capacity;  // allocated storage
    double * val;     // pointer to first element
} array_t;

enum storage_order { RowMajor, ColMajor };
typedef struct array2d /* two-dimensional array */
{
    size_t shape[2];           // number of rows and cols.
    enum storage_order order;  // RowMajor or ColMajor
    double *val;               // pointer to first element
} array2d_t;

// int array2d_scale_rows(array_t *alpha, array2d_t *A);

// int main(){
//     //allocation for debugging
//     double a_arr[10] = {1,2,3,4,2,4,5,17,39,12}, alpha_arr[2] = {2,3};
//     int n = 5;
//     int m = 2;
//     array_t * alpha = (array_t*)malloc(n*sizeof(array_t));
//     alpha->len = (size_t)2;
//     alpha->val = alpha_arr;
//     array2d_t * M = (array2d_t*)malloc(n*n*sizeof(array2d_t));
//     M->shape[0] = m;
//     M->shape[1] = n;
//     M->order = RowMajor;
//     M->val = a_arr;

//     //testing output
//     for(int i=0;i<m;i++){
//         printf("\n");
//         for(int j=0;j<n;j++){
//             printf("%f, ",M->val[i*n+j]);
//         }
//     }
//     int outers = array2d_scale_rows(alpha,M);
//     printf("\nouters is %d\n",outers);
//     printf("\nafter scaling:\n");
//     for(int i=0;i<m;i++){
//         printf("\n");
//         for(int j=0;j<n;j++){
//             printf("%f, ",M->val[i*n+j]);
//         }
//     }
//     return 0;
// }


// //alternative solution for e.g. row major
// int array2d_scale_rows(array_t *alpha, array2d_t *A){
//     if(!A||!alpha||alpha->len!=A->shape[0]){return 1;}
//     if(A->order==RowMajor){
//         for(size_t i=0;i<A->shape[0];i++){
//             double s = alpha->val[i];
//             double *p = A->val+i*A->shape[1];
//             for(size_t j=0;j<A->shape[1];j++){
//                 p[j] *= s;
//             }       
//         }
//     }
//     return 0;
// }



//solution
int array2d_scale_rows(array_t *alpha, array2d_t *A){
    if(!A||!alpha||alpha->len!=A->shape[0]){return 1;}
    if(A->order==RowMajor){
        size_t n = A->shape[1];
        size_t m = A->shape[0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                A->val[i*n+j]*=alpha->val[i];
            }       
        }
    }
    if(A->order==ColMajor){
        for(int i=0;i<A->shape[1];i++){
            for(int j=0;j<A->shape[0];j++){
                A->val[j+i*A->shape[0]]*=alpha->val[j];
            }
        }
    }
    return 0;
}


