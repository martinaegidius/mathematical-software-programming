#include <stdio.h>

int main(void){
    double a = 2.1;
    char string = (char)a;
    int b = (int)string;
    int c = (int)a;
    printf("%d",c);
    double d = (double)c;
    printf("%f",d);
    return 0;
}