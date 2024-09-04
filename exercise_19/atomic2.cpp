#include <iostream>
#include <thread>
#include <atomic>

class Counter
{
public:
    Counter() : value(0) {}
    int get() const { return value; }
    void increment() { ++value; }

private:
    int value;
};

std::atomic<Counter> shared_counter;

/// Increments the shared counter a million times using an atomic compare-and-exchange loop.
/// This function is called from the main thread to update the shared counter.
void increment_shared_counter()
{
    for (int i = 0; i < 1000000; ++i)
    {
        Counter current = shared_counter.load();
        Counter new_value;
        do
        {
            new_value = current;
            new_value.increment();
        } while (!shared_counter.compare_exchange_weak(current, new_value));
    }
}

int main()
{
    std::thread t1(increment_shared_counter);
    std::thread t2(increment_shared_counter);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_counter: " << shared_counter.load().get() << std::endl;

    return 0;
}
