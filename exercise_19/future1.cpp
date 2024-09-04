#include <iostream>
#include <future>
#include <thread>

void calculate_sum(std::promise<int> &&promise, int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long calculation
    promise.set_value(a + b);                             // Set the result
}

int main()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    // Start a thread to perform the calculation
    std::thread calculation_thread(calculate_sum, std::move(promise), 10, 20);

    std::cout << "Waiting for the result..." << std::endl;

    // Wait for the result and print it
    std::cout << "Result: " << future.get() << std::endl;

    calculation_thread.join();

    return 0;
}