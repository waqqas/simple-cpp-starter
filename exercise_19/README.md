
# std::thread

`std::thread` is a class in C++ that represents a single thread of execution. It's part of the C++11 standard and provides a way to create and manage threads in a portable manner.

## Key features:

1. Easy thread creation
2. Joinable and detachable threads
3. Thread identification
4. Support for move semantics

## Basic usage:


#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(hello);  // Create a thread and start executing the 'hello' function
    t.join();  // Wait for the thread to finish

    return 0;
}


## Example with parameters and lambda:


#include <iostream>
#include <thread>
#include <string>

int main() {
    std::string message = "Hello from lambda thread!";

    std::thread t([&message]() {
        std::cout << message << std::endl;
    });

    t.join();

    return 0;
}


## Important considerations:

1. Always join or detach threads before they go out of scope.
2. Be careful with data races and use appropriate synchronization mechanisms (e.g., mutexes) when sharing data between threads.
3. Use `std::async` for tasks that return values.
4. Consider using higher-level abstractions like `std::async`, `std::future`, and `std::promise` for more complex scenarios.

Remember to compile with thread support, e.g., using `-pthread` flag with GCC:


g++ -std=c++11 -pthread your_file.cpp -o your_program




## std::mutex and how to use it

`std::mutex` is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads. It provides mutual exclusion, ensuring that only one thread can access the protected resource at a time.

Here's an example of how to use `std::mutex`:


#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Declare a global mutex
int shared_variable = 0;

void increment_shared_variable() {
    for (int i = 0; i < 1000000; ++i) {
        mtx.lock();  // Lock the mutex before accessing the shared resource
        ++shared_variable;
        mtx.unlock();  // Unlock the mutex after accessing the shared resource
    }
}

int main() {
    std::thread t1(increment_shared_variable);
    std::thread t2(increment_shared_variable);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_variable: " << shared_variable << std::endl;

    return 0;
}


Key points about using `std::mutex`:

1. Include the `<mutex>` header to use `std::mutex`.
2. Create a `std::mutex` object to protect your shared resource.
3. Use `mutex.lock()` before accessing the shared resource and `mutex.unlock()` after you're done.
4. Always ensure that you unlock the mutex, even if an exception is thrown. To make this easier, you can use `std::lock_guard` or `std::unique_lock`:


void increment_shared_variable() {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // Automatically locks and unlocks the mutex
        ++shared_variable;
    }
}


5. Be careful to avoid deadlocks. Always lock mutexes in the same order across all threads if you need to lock multiple mutexes.

6. Consider using `std::atomic` for simple operations on integral types, as it can be more efficient than using a mutex.

Remember that while mutexes are essential for thread safety, overuse can lead to performance issues due to thread contention. Design your multithreaded code to minimize the need for synchronization where possible.


`std::lock_guard` is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block. When a `lock_guard` object is created, it attempts to take ownership of the mutex it is given. When control leaves the scope in which the `lock_guard` object was created, the `lock_guard` is destructed and the mutex is released.

The main advantages of using `lock_guard` are:
1. It's exception-safe: the mutex will be unlocked even if an exception is thrown.
2. It prevents forgetting to unlock the mutex.
3. It makes the code cleaner and more readable.

Here's the program converted to use `lock_guard`:

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Declare a global mutex
int shared_variable = 0;

void increment_shared_variable() {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // Automatically locks the mutex
        ++shared_variable;
        // The lock_guard automatically unlocks the mutex when it goes out of scope
    }
}

int main() {
    std::thread t1(increment_shared_variable);
    std::thread t2(increment_shared_variable);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_variable: " << shared_variable << std::endl;

    return 0;
}

In this version, we've replaced the explicit `lock()` and `unlock()` calls with a `std::lock_guard` object. The `lock_guard` constructor locks the mutex, and its destructor unlocks the mutex. This ensures that the mutex is always unlocked, even if an exception is thrown within the critical section.



`std::atomic` is a template class that provides atomic operations on an enclosed value. It ensures that the operations on the value are atomic, meaning they are indivisible and cannot be interrupted by other threads. This makes `std::atomic` useful for lock-free programming and can often be more efficient than using mutexes for simple operations.

Key features of `std::atomic`:
1. Atomic operations: All operations on the atomic object are guaranteed to be atomic.
2. Memory ordering: It allows you to specify the memory ordering of operations.
3. Lock-free: For most types, operations on atomic objects are lock-free.

Here's the program converted to use `std::atomic` instead of `lock_guard`:

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> shared_variable(0);  // Declare an atomic variable

void increment_shared_variable() {
    for (int i = 0; i < 1000000; ++i) {
        ++shared_variable;  // Atomic increment operation
    }
}

int main() {
    std::thread t1(increment_shared_variable);
    std::thread t2(increment_shared_variable);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_variable: " << shared_variable.load() << std::endl;

    return 0;
}

In this version:
1. We've replaced `int shared_variable` with `std::atomic<int> shared_variable(0)`.
2. The increment operation `++shared_variable` is now atomic, so we don't need a mutex or lock_guard.
3. We use `shared_variable.load()` to get the final value, which ensures an atomic read operation.

This version is simpler and potentially more efficient, as it avoids the overhead of locking and unlocking a mutex for each increment operation. However, `std::atomic` is best suited for simple operations like this. For more complex operations or when you need to protect larger critical sections, mutexes are still necessary.



`std::future` and `std::promise` are components of the C++ Standard Library that facilitate asynchronous programming. They provide a way to access the result of asynchronous operations.

`std::future`:
- Represents the result of an asynchronous operation.
- Acts as a handle to a shared state that will contain the result of an asynchronous operation.
- Provides methods to check if the result is available, wait for the result, and retrieve the result.

`std::promise`:
- Used to set the value or exception in the shared state associated with a future.
- Acts as the "producer" end of a future, while `std::future` is the "consumer" end.

Here's an example demonstrating the usage of `std::future` and `std::promise`:


#include <iostream>
#include <future>
#include <thread>

void calculate_sum(std::promise<int>&& promise, int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate long calculation
    promise.set_value(a + b); // Set the result
}

int main() {
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


In this example:
1. We create a `std::promise<int>` and get its associated `std::future<int>`.
2. We start a new thread that calls `calculate_sum`, passing the promise, and two integers to add.
3. The `calculate_sum` function simulates a long calculation, then sets the result using `promise.set_value()`.
4. In the main thread, we wait for and retrieve the result using `future.get()`.

This demonstrates how `std::future` and `std::promise` can be used to pass results between threads in an asynchronous manner.
