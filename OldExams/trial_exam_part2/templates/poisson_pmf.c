#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double poisson_pmf(unsigned long k, double lambda) {
  if(lambda<=0 || isnan(lambda)){
    return NAN;
  }
  else{
    return exp(k*log(lambda)-lgamma(k+1)-lambda);
  }
}

int main(){
  double lambda = 2.0;
  unsigned long k = 2;
  double out = poisson_pmf(k,lambda);
  printf("%f",out);
  return 0;
}
