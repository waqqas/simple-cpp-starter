#include <stdio.h>

void updateValue(int *ptr)
{
    *ptr = 42; // Update the value pointed to by ptr
}

int main()
{
    int value = 0;
    printf("Before update: %d\n", value);

    updateValue(&value); // Pass the address of value

    printf("After update: %d\n", value);

    return 0;
}