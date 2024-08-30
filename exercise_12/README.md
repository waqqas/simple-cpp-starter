
# std::shared_ptr

`std::shared_ptr` is a smart pointer provided by the C++ Standard Library that manages the lifetime of dynamically allocated objects through shared ownership. It is part of the `<memory>` header and was introduced in C++11.

## Key features:

1. Reference counting: `shared_ptr` maintains a count of how many instances are pointing to the same object.
2. Automatic memory management: When the reference count reaches zero, the managed object is automatically deleted.
3. Thread-safe reference counting: The reference count is incremented and decremented in a thread-safe manner.

## Usage:


#include <memory>

// Creating a shared_ptr
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);

// Copying a shared_ptr
std::shared_ptr<int> ptr2 = ptr1;

// Accessing the managed object
std::cout << *ptr1 << std::endl; // Outputs: 42

// Check if the pointer is unique
bool isUnique = ptr1.unique(); // Returns false, as ptr2 also owns the object

// Get the number of shared_ptr instances managing the object
long useCount = ptr1.use_count(); // Returns 2

// Reset the shared_ptr
ptr1.reset(); // ptr1 no longer owns the object, but ptr2 still does


## Benefits:

- Prevents memory leaks by ensuring proper deletion of dynamically allocated objects.
- Allows for shared ownership of resources among multiple pointers.
- Provides a safe way to pass ownership of dynamically allocated objects between functions.

## Considerations:

- Slight performance overhead due to reference counting.
- Potential for circular references if not used carefully (can be mitigated with `std::weak_ptr`).
- Not suitable for arrays (use `std::shared_ptr<T[]>` or `std::vector` instead).

`std::shared_ptr` is a powerful tool for managing dynamic memory in C++, especially in scenarios where multiple objects need to share ownership of a resource.


## std::make_shared()

`std::make_shared()` is a function template provided by the C++ Standard Library that creates and returns a `std::shared_ptr`. It is the recommended way to create a `shared_ptr` because it offers several advantages:

1. Exception safety: If an exception is thrown during object construction, no memory leak occurs.
2. Efficiency: It allocates memory for both the managed object and the control block in a single allocation, which can be more efficient than separate allocations.

### Usage:


// Creating a shared_ptr with make_shared
auto ptr = std::make_shared<int>(42);

// Creating a shared_ptr to a custom class
class MyClass {
public:
    MyClass(int a, double b) : m_a(a), m_b(b) {}
private:
    int m_a;
    double m_b;
};

auto obj = std::make_shared<MyClass>(10, 3.14);

// Creating a shared_ptr to an array (C++20 and later)
auto arr = std::make_shared<int[]>(5);


### Benefits:

- Improved performance due to a single allocation.
- Cleaner and more concise syntax.
- Helps prevent common errors associated with manual memory management.

`std::make_shared()` is an essential part of modern C++ programming when working with dynamically allocated objects and shared ownership semantics.


## Control Block in std::shared_ptr

The control block is an internal data structure used by `std::shared_ptr` to manage the shared ownership of the pointed-to object. It contains critical information for the proper functioning of the shared pointer:

1. Reference count: Keeps track of how many `shared_ptr` instances are pointing to the managed object.

2. Weak count: Tracks the number of `weak_ptr` instances observing the object.

3. Deleter: A function object responsible for destroying the managed object when the reference count reaches zero.

4. Allocator: Used for memory management of the control block itself.

5. Pointer to the managed object: Allows the control block to access and manage the object.

### Key aspects of the control block:

- Created when a `shared_ptr` is constructed for the first time for an object.
- Shared among all `shared_ptr` instances pointing to the same object.
- Automatically destroyed when the last `shared_ptr` is destroyed and the reference count reaches zero.
- Enables thread-safe reference counting through atomic operations.
- Facilitates proper cleanup of resources when no more `shared_ptr` instances are referencing the object.

The control block is an essential component that enables the sophisticated memory management capabilities of `std::shared_ptr`, ensuring safe and efficient shared ownership of dynamically allocated objects in C++.

