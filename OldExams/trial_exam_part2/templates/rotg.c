#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void rotg(double a, double b, double * c, double * s){
  double r = hypot(a,b);
  if(r == 0){
    *c = 1.0;
    *s = 0.0;
  }
  else{
    *c = a/r;
    *s = -b/r;
  }
  return;
}

int main(){
  double*c = (double*)malloc(sizeof(double));
  double*s = (double*)malloc(sizeof(double));
  double a = 2.0;
  double b = 3.0;
  rotg(a,b,c,s);
  printf("%f\n%f",*c,*s);
  return 0;
}