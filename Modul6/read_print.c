#include "msptools/include/msptools.h"
#include <stdio.h>

int main(int argc,char *argv[]){
    array2d_t * read = array2d_from_file(argv[1]);
        if(!read){return -1;}
    else{
        array2d_print(read);
        return 1;
    }
}