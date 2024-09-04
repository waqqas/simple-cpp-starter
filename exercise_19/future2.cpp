#include <iostream>
#include <future>
#include <thread>

void calculate_sum(std::promise<int> &&promise, int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long calculation

    int sum = a + b;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    if (sum % 2 != 0)
    {
        promise.set_exception(std::make_exception_ptr(std::runtime_error("Sum is odd")));
    }
    else
    {
        promise.set_value(sum); // Set the result
    }
}
int main()
{
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Start a thread to perform the calculation
    std::thread calculation_thread(calculate_sum, std::move(promise), std::rand() % 10 + 1, std::rand() % 10 + 1);
    std::cout << "Waiting for the result..." << std::endl;

    // Wait for the result and print it
    try
    {
        std::cout << "Result: " << future.get() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    calculation_thread.join();

    return 0;
}