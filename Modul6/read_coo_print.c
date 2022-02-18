#include "msptools/include/msptools.h"
#include <stdio.h>

int main(int argc,char *argv[]){
    coo_t * read = coo_from_file(argv[1]);
        if(!read){return -1;}
    else{
        coo_print(read);
        return 1;
    }
}