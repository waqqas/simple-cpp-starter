#include <iostream>

class Multiplier
{
private:
    int factor;

public:
    Multiplier(int f) : factor(f) {}

    int operator()(int x) const
    {
        return x * factor;
    }
};

int main()
{
    // Usage
    Multiplier times3(3);
    int result = times3(5); // result is 15

    std::cout << "result: " << result << std::endl;

    return 0;
}
