#include <stdio.h>

int main()
{
    // This is actually 7 tests...We always have one more than expected
    for (int i = 0; i <= 10; i += 2)
    {
        printf("test %d\n", i);
    }
    return 0;
}