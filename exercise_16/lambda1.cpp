#include <iostream>

int main()
{
    int x = 10;
    auto increment = [x]() mutable
    { return ++x; };
    std::cout << increment() << std::endl; // Outputs: 11
    std::cout << x << std::endl;           // Outputs: 10 (original x is unchanged)

    int count = 0;
    auto counter = [count]() mutable
    {
        return ++count;
    };

    std::cout << counter() << std::endl; // Outputs: 1
    std::cout << counter() << std::endl; // Outputs: 2
    std::cout << count << std::endl;     // Outputs: 0

    return 0;
}