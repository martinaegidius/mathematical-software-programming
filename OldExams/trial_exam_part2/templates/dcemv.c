#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int dcemv(int n, double * x) {
  double mean = 0.0;
  for(int i=0;i<n;i++){
    mean += x[i]; //lægger alle vektor-værdier sammen
  }
  mean /= n; //finder gennemsnittet af dem
  for(int i=0;i<n;i++){
    x[i]-=mean; //trækker gennemsnittet fra hvert element
    printf("%f, ",x[i]);
  }
  
  return 0;
}

int main(){
    double A[3]={2,3,5};
    double *arr;
    arr = A;
    int n = 3; //nxn matrix boi
    int call = dcemv(n,arr);
    return 0;
}
