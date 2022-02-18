#include <stdio.h>
#include <stdlib.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest){
    if(n<2) return;
    
    *largest = a[0]>=a[1] ? a[0] : a[1];
    *second_largest = a[0]>=a[1]?a[1]:a[0];
    // if(a[0]>a[1]){         //ternary could also be written as
    //     *largest = a[0];
    //     *second_largest = a[1];
    // }
    // else{
    //     *largest = a[1];
    //     *second_largest = a[0];
    // }
    for(int i=2;i<n;i++){
        if(a[i]>*largest){
            *second_largest = *largest;
            *largest = a[i];
        }
        else if (a[i]>*second_largest){
            *second_largest = a[i];
        }
    }

}

int main(){
    int a[4] = {1,5,100,7};
    int *largest = malloc(sizeof(int));
    int *second_largest = malloc(sizeof(int));
    int n;
    n = 4;
    find_two_largest(a,n,largest,second_largest);
    printf("\nlargest %d",*largest);
    printf("\n2nd largest %d",*second_largest);
    return 0;     
}