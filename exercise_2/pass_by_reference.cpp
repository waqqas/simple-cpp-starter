#include <iostream>

void updateValue(int &ref)
{
    ref = 42; // Update the value referenced by ref
}

int main()
{
    int value = 0;
    int value2 = 2;

    // int &ref_to_value;

    int &ref_to_value = value;
    ref_to_value = value2;

    std::cout << "Before update: " << value << std::endl;

    updateValue(value); // Pass value by reference

    std::cout << "After update: " << value << std::endl;

    return 0;
}