#include <iostream>
#include <limits>
#include <cmath>

int main()
{
    // Integer limits
    std::cout << "Int max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Int min: " << std::numeric_limits<int>::min() << std::endl;

    // Floating-point limits
    std::cout << "Float epsilon: " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "Double lowest: " << std::numeric_limits<double>::lowest() << std::endl;

    // Type properties
    std::cout << "Is int signed? " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "Digits in double: " << std::numeric_limits<double>::digits << std::endl;

    return 0;
}