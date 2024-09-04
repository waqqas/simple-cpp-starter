#include <iostream>
#include <stdexcept>

double divide(double a, double b)
{
    if (b == 0)
    {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main()
{
    try
    {
        std::cout << divide(10, 2) << std::endl; // OK
        std::cout << divide(10, 0) << std::endl; // This will throw an exception
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}