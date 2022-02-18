#include <stdio.h>

int sum_array(const int a[],int n){
    int sum = 0,*p;
    for(p=a;p<a+n;p++){
        sum += *p;
    }
    return sum;
}

int main(){
    int a[5] = {1,2,3,4,100};
    int n = 5;
    int sum = sum_array(a,n);
    printf("%d",sum);
    return 0;
}