#include <stdio.h>
#include <math.h>

////without recursion boi
// int faculty(int n){
//     int initializer = 1;
//     for(int i = 1;i<=n;i++){
//         initializer = initializer*i;
//     }
//     return initializer;
// }

//with recursion
int faculty(int n){
    int res = 1;
    if(n==0){ //base case
        return res;
    }
    else{
        res = faculty(n-1)*n;
        return res;

    }
}

double logfactorial(int n){
    //double res = log(faculty(n)); //bad idea as factorial overflows to quickly
    double res = lgamma(n+1);
    return res;
}

int main(){
    int n =1000;
    int out = faculty(n);
    printf("%d",out);
    double out2 = logfactorial(n);
    printf("log is %f",out2);
    return 0;
}