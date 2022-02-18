#include <stdlib.h>
#include <stdio.h>

int *create_array(int n, int initial_value){
    if (n<1) return NULL;
    int * array = malloc(n*sizeof(*array));
    if(!(array)){return NULL;}
    for(int i=0;i<n;i++){
        array[i] = initial_value;
    }
    return array;
}

int main(){
    int n = 4, initial_value = 2,*ptr;
    ptr = create_array(n,initial_value);
    printf("allocated array: \n");
    for(int i=0;i<n;i++){
        printf("%d\n",ptr[i]);
    }    
    free(ptr);
    return 0; 
}