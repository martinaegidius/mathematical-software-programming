#include <stdio.h>


struct complex{
        double real;
        double imaginary;
    };

int main(){
    struct complex c5 = {13,13};
    struct complex c1,c2,c3;
    c1.real = 0.0;
    c1.imaginary = 1.0;
    c2.real = 1.0;
    c2.imaginary = 0.0;
    c1 = c2; //complete copy of struct
    printf("\nreal part c1: %f",c1.real);
    printf("\nimaginary part c1: %f",c1.imaginary);
    c3.real = c1.real+c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    printf("\nreal part c3: %f",c3.real);
    printf("\nimaginary part c3: %f",c3.imaginary);
    printf("\nc4 R=%f, I=%f",c5.real,c5.imaginary);
    return 0;
}