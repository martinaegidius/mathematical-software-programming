#include <stdio.h>
#include <stdlib.h>

int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n,sizeof(int)); //sometimes you want to zero-initialize. This could work with malloc, but only if random memory treats you nicely. 
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
       a[i] = a[i] - 2;
       printf("%d ",a[i]);
   }
   free( a );
   
   return(0);
}