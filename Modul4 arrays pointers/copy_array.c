#include <stdio.h>
#include <string.h>

int main(void) {

  double arr1[4] = {1.0, 2.0, 3.0, 4.0};
  double arr2[4];
  size_t n = sizeof(arr1);

  memcpy(arr2, arr1, n);

  /* Test: print out contents of arr2 */
  for (int i=0; i<sizeof(arr2)/sizeof(double); i++)
    printf("%.2f ", arr2[i]);

  return 0;
}