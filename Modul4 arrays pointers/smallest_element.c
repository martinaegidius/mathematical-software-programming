#include <stdlib.h>
#include <stdio.h>
//#include <math.h>
double * find_smallest(double * arr, int n) {
    double * smallest = arr;
    if (arr==NULL) return NULL;
    for(int i=0;i<n;i++){
        if(arr[i]<*smallest || isnan(*smallest)){
            smallest = arr+i;
        }
    }
    return smallest;
}

int main(void){
    double vals[4] = {-12,12,-12.1,-2},*arr;
    arr = vals;
    int n = 4;
    double * outers = find_smallest(arr,n);
    printf("smallest element is %f",*outers);
    return 0;
}