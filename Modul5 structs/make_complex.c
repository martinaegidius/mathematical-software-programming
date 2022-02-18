#include <stdio.h>

struct complex{
        double real;
        double imaginary;
    };

struct complex make_complex(double a, double b){
    struct complex c = {a,b};
    return c;
}

struct complex add_complex(struct complex a,struct complex b){
    struct complex c = {a.real+b.real,a.imaginary+b.imaginary};
    return c;
}

int main(){
    struct complex c1,c2,c3;
    double a = 2.0;
    double b = 4.0;
    struct complex c4 = make_complex(a,b);
    printf("c4 R=%f, I=%f",c4.real,c4.imaginary);
    struct complex cSum = add_complex(c4,c4);
    printf("sum R=%f,I=%f",cSum.real,cSum.imaginary);
    return 0;
}