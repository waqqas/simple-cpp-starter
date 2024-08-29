#include <iostream>

inline int MAX(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    int num1 = 10;
    int num2 = 20;
    int maxNum = MAX(num1, num2);

    std::cout << "The maximum number is: " << maxNum << std::endl;

    return 0;
}