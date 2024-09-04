#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Hello from thread!" << std::endl;
}

int main()
{
    std::thread t(hello); // Create a thread and start executing the 'hello' function
    t.join();             // Wait for the thread to finish

    return 0;
}

// EXERCISE: convert to lambda function