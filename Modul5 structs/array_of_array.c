#include <stdio.h>
#include <stdlib.h>


typedef struct carray2d /* C-style two-dimensional array */
{
    size_t shape[2];
    double **val;
} carray2d_t;

carray2d_t *carray2d_alloc(const size_t shape[2]) {
    carray2d_t *a = malloc(sizeof(*a));
    if (a == NULL) { return NULL; }
    a->shape[0] = shape[0];
    a->shape[1] = shape[1];
    a->val = malloc(shape[0] * sizeof(*(a->val)));
    if (a->val == NULL) { free(a); return NULL; }
    a->val[0] = calloc(shape[0] * shape[1], sizeof(*(a->val[0])));
    if (a->val[0] == NULL) { free(a->val); free(a); return NULL; }
    for (size_t k = 1; k < shape[0]; k++)
        a->val[k] = a->val[0] + k*shape[1];
    return a;
}

void carray2d_dealloc(carray2d_t *a) {
    if (a) {
        free(a->val[0]);
        free(a->val);
        free(a);
    }
}

int carray2d_add_diag(const double alpha, carray2d_t *A){
    if(!A||A->shape[0]!=A->shape[1]){
        return 1;
    }
    for(int i=0;i<A->shape[1];i++){
        A->val[i][i] += alpha;
    }
    return 0;
}

int main(){
    //allocating c-style array and filling diagonal
    carray2d_t * a = carray2d_alloc((size_t []){3,3});
    for(int i=0;i<3;i++){
        a->val[i][i]=3.0;
    }
    //printing cstyle array
    for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<3;j++){
            printf("%f, ",a->val[j][i]);
        }
    }
    double alpha = 2.0;
    int outers = carray2d_add_diag(alpha,a);
    printf("\nprinting output:\n");
    for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<3;j++){
            printf("%f, ",a->val[j][i]);
        }
    }
    return 0;
}

