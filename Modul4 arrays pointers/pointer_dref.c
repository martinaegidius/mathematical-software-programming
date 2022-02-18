#include <stdlib.h>
#include <stdio.h>

//extern double *arr;   // Pointer to first element of array
extern int n;             // Number of elements

int main(void) {
    int n = 6;
    double a[6] = {-1,2,-5,2,17,-12},*arr;
    arr = a;
        if (arr == NULL) return EXIT_FAILURE;

    /* Insert your code here 
    #include <stdio.h>
int main(void){
    int arr[10] = {19,74,13,67,44,80,7,36,9,77},*p = arr;
    double sum = 0.0;
    for (int i = 0;i<10;i++){
        sum +=*p; //add current pointer value 
        p++; //increment pointer-location
    }*/


    for(int i=0;i<n;i++){
        if(*arr<0){
            printf("\n%f smol",*arr);
            *arr=0.0;
        }
        else{
            printf("\n%f big",*arr);
        }
        printf("\n now %f",*arr);
        arr++;
        printf("\n%f",*arr);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%2.f",arr[i]);
    }

    /* Test: print elements of arr */
//    for (int j=0; j<n; j++)
  //  	printf("%.2f ", arr[j]);

    return 0;
} 