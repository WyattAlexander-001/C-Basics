#include <stdio.h>

int myBadFunction(int a, int b)
{
    printf("hi,,, %d", a); // good so far…
    printf(“inside badFunction, a = % d, b = % d\n”, a, b);
    // guts of myBadFunction
    printf(“leaving myBadFunction, returning % d\n”);
}

int main()
{
    myBadFunction(100, 50);
    return 0;
}