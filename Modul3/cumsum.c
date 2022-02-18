#include <stdio.h>

int main(void) {

    double arr[5] = {1.0, 0.1, -2.0, 3.0, -0.1};
    double cumsum = 0;
    /* Insert your code here */
    for(int i=0;i<5;i++){
        cumsum += arr[i];
        arr[i] = cumsum;
    }

    /* Test: print out values */
    for (int i=0; i < sizeof(arr)/sizeof(*arr); i++)
        printf("%.2f ", arr[i]);

    return 0;
}