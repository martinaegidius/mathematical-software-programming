#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double weighted_harmonic_mean(int n, double * x, double * w) {
    if(n<=0||!(x)||!(w)){
        return NAN;
    }
    else{
        double seqsumW,seqsumX;
        seqsumW = 0.0;
        seqsumX = 0.0;
        for(int i=0;i<n;i++){
            if(x[i]==0){
                return NAN;
            }
            seqsumW += w[i];
            seqsumX += w[i]/x[i];
        }
        if(seqsumX==0||isnan(seqsumX)||isnan(seqsumW)){
            return NAN;
        }
        else{return seqsumW/seqsumX;}
    }
}
int main(){
    int n = 4;
    double * x, * w,x_arr[4]={1,2,3,100},w_arr[4]={2,1,4,12},outers;
    x = x_arr;
    w = w_arr;
    outers = weighted_harmonic_mean(n,x,w);
    printf("%f",outers);
    return 0;
}
