#include <stdio.h>

int main(void){
    printf("%6d, %4d",86,1040);
    printf("\n%12.5e",30.253); //first part of number is the precision 
    //which just shows how precise the evaluation is. Second part is shown number of digits after the dec.point
    printf("\n%.4f",83.162); //still indicates number of digits after decimal-point
    printf("\n%-6.2g",0.0000009979); //uses shortest rep. of %e or %f. - forces to left in field-width 
    //(ie. zero-padding after number instead of before)
    return 0;
}