
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Declare a global mutex
int shared_variable = 0;

void increment_shared_variable()
{
    for (int i = 0; i < 1000000; ++i)
    {
        mtx.lock(); // Lock the mutex before accessing the shared resource
        ++shared_variable;
        mtx.unlock(); // Unlock the mutex after accessing the shared resource
    }
}

int main()
{
    std::thread t1(increment_shared_variable);
    std::thread t2(increment_shared_variable);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_variable: " << shared_variable << std::endl;

    return 0;
}
