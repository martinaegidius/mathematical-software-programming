#include <stdio.h>
int main(void){
    int arr[10] = {19,74,13,67,44,80,7,36,9,77},*p = arr;
    double sum = 0.0;
    for (int i = 0;i<10;i++){
        sum +=*p; //add current pointer value 
        p++; //increment pointer-location
    }
    /*
    int i = -1;
    while (++i<10){ //
        val += *(p++); //this is a weird way of dereferencing pointer value at increment
    }
    */
    sum /= 10;
    printf("Value: %.2f\n",sum);
    return 0;
}