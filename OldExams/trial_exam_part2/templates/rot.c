#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int rot(double c, double s, int n, double * x, double * y){
  
  if(!x||!y||n<1||fabs(c)>1||fabs(s)>1){return -1;}
  //check if idiotreglen is opfyldt
  if(fabs(c*c+s*s-1)>ldexp(1.0,-50)) return -1;
  
  double tmp_holder;
  for(int i=0;i<n;i++){
    tmp_holder = c*x[i]-s*y[i];
    y[i] = s*x[i]+c*y[i];
    x[i] = tmp_holder;
  }

// // //printing module
// printf("\nx:       y:\n");
// for(int i=0;i<n;i++){
//   printf("%f,%f\n",x[i],y[i]);
// }
  
  return 0;
}

int main(){
  double c = 0.9;
  double s = 1.4;
  double x_val[4] = {1,2,3,4};
  double y_val[4] = {14,2,1,5};
  int n = 4;
  double * x = x_val;
  double * y = y_val;
  int outers = rot(c,s,n,x,y);
  printf("\nexit code %d",outers);
  return 0;
}

