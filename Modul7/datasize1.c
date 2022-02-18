extern double arr[];
int datasize1(int elem) {
    for (int i=0; i<elem; i++) arr[i] *= 3;
    return(elem);
}