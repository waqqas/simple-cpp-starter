#include <iostream>

void print(int num)
{
    std::cout << "Integer: " << num << std::endl;
}

void print(float num)
{
    std::cout << "Float: " << num << std::endl;
}

int main()
{
    int a = 10;
    float b = 3.14f;

    print(a);
    print(b);

    return 0;
}