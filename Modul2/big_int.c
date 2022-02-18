#include <stdio.h>
#include <limits.h>

int main(void){
    unsigned long x = 2343432205;
    printf("%lu\n",sizeof(x));
    printf("%lx",x);
    printf("val %u",(unsigned int) UINT_MAX);
    printf("val %lu",(unsigned long) ULONG_MAX);

    return 0;
}