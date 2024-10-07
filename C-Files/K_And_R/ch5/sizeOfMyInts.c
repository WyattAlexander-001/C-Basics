#include "stdio.h"

int main(void){
    printf("size of a short is %d\n", sizeof(short));
    printf("size of a int is %d\n", sizeof(int));
    printf("size of a long is %d\n", sizeof(long));

    int j, k;
    int *ptr;

    j = 117;
    k = 69;
    ptr = &k;

    printf("\n");
    printf("j has the value %d and is stored at %p\n", j, (void *)&j); //%p is used to print the address of the variable
    printf("k has the value %d and is stored at %p\n", k, (void *)&k);
    *ptr = 99;
    printf("k has the value %d and is stored at %p\n", k, (void *)&k);
    printf("ptr has the value %p and is stored at %p\n", ptr, (void *)&ptr); //ptr has the same value as the address of k but is stored at a different address
    printf("The value of the integer pointed to by ptr is %d\n", *ptr);

    return 0;
}
// To compile the code, open the terminal and run the following command
// gcc sizeOfMyInts.c -o sizeOfMyInts.exe
// .\sizeOfMyInts.exe