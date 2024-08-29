#include <stdio.h>

void printInt(int num)
{
    printf("Printing an integer: %d\n", num);
}

void printFloat(float num)
{
    printf("Printing a float: %f\n", num);
}

int main()
{
    int a = 10;
    float b = 3.14;

    printInt(a);
    printFloat(b);

    return 0;
}