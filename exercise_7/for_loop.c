
#include <stdio.h>

#define ARRAY_SIZE 5

int main()
{
    int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    printf("Array elements:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
