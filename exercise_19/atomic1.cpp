#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> shared_variable(0); // Declare an atomic variable

void increment_shared_variable()
{
    for (int i = 0; i < 1000000; ++i)
    {
        ++shared_variable; // Atomic increment operation
    }
}

int main()
{
    std::thread t1(increment_shared_variable);
    std::thread t2(increment_shared_variable);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_variable: " << shared_variable.load() << std::endl;

    return 0;
}