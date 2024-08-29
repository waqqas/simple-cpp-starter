#include <iostream>
#include <array>

#define ARRAY_SIZE 5

int main()
{
    int numbers[ARRAY_SIZE] = {1, 2, 3, 4, 5};

    std::cout << "Array elements:\n";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
