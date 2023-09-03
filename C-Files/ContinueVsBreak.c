#include <stdio.h>

int main()
{
    // continue = skips rest of code & forces the next iteration of the loop
    // break = exits a loop/switch

    for (int i = 0; i < 20; i++)
    {
        if (i == 3)
        {
            // Comment out one
            // continue;
            // break;
        }
        printf("This is i = %d\n", i);
    }

    return 0;
}