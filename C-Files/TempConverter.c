#include <stdio.h>
#include <ctype.h>

int main()
{
    char unit;
    float temp;
    printf("Is the Temp in F or C?:\n");
    scanf("%c", &unit);
    unit = toupper(unit);

    if (unit == 'C')
    {
        printf("Enter the Temp in Celcius\n");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("Temp in F:%.2f\n", temp);
    }
    else if (unit == 'F')
    {
        printf("Enter the Temp in Farenheit\n");
        scanf("%f", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("Temp in C:%.2f", temp);
    }
    else
    {
        printf("Error Bro");
    }
    return 0;
}