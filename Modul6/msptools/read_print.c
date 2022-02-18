#include "msptools.h"
#include <stdio.h>

int main(){
    char filename[] = "msptools/data/A1.txt";
    array2d_t * read = (array2d_t*)array2d_from_file(filename);
    if(!read){
        printf("erorr boii");
    }
    return 0;
    
    
}