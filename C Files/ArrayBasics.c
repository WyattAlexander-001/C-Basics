#include <stdio.h>

int main()
{
    // array = a data structure that can store many values of the SAME data type.
    // Much different from JS
    // double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0}; //Pre-make arr
    double prices[10];

    prices[0] = 5.0;
    prices[1] = 10.0;
    prices[2] = 15.0;
    prices[3] = 25.0;
    prices[4] = 20.0;
    prices[9] = 99.7;

    // printf("$%.2lf", prices[0]);

    for (int i = 0; i < sizeof(prices) / sizeof(prices[0]); i++)
    {
        printf("$%.2lf\n", prices[i]);
    }

    return 0;
}