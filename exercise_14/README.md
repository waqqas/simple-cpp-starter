
# Exercise 14: Template Basics

## Introduction
Templates in C++ are a powerful feature that allows you to write generic code that can work with different data types. They enable you to create functions and classes that can operate on various data types without the need for separate implementations for each type.

## Key Concepts

1. Function Templates
   - Allow you to write a single function that can work with multiple data types.
   - Syntax: `template <typename T> returnType functionName(T parameter) { ... }`

2. Class Templates
   - Enable you to create classes that can work with different data types.
   - Syntax: `template <typename T> class ClassName { ... }`

3. Template Parameters
   - Can be types (using `typename` or `class`) or non-type parameters (like integers).
   - Multiple parameters are allowed: `template <typename T, typename U, int N>`

4. Template Specialization
   - Allows you to provide a specific implementation for a particular data type.

5. Template Instantiation
   - The process of creating a concrete function or class from a template.

## Benefits
- Code reusability
- Type safety
- Flexibility in handling different data types

## Example

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage
int maxInt = max(10, 20);        // Works with integers
double maxDouble = max(3.14, 2.71);  // Works with doubles


In this exercise, you'll practice creating and using basic function and class templates to understand how they work and their benefits in C++ programming.



## Template Specialization

Template specialization is a feature in C++ that allows you to provide a specific implementation of a template for a particular data type. This is useful when you want to optimize or customize the behavior of a template for a specific type.

### Key points:
- Allows for type-specific optimizations or implementations
- Can be applied to both function and class templates
- Syntax: `template <> returnType functionName<SpecificType>(SpecificType parameter) { ... }`

### Example:


// General template
template <typename T>
void print(T value) {
    std::cout << "General template: " << value << std::endl;
}

// Specialization for int
template <>
void print<int>(int value) {
    std::cout << "Specialized template for int: " << value << std::endl;
}

// Usage
print<double>(3.14);  // Uses general template
print<int>(42);       // Uses specialized template for int


In this example, the `print` function has a general template that works for any type, but a specialized version is provided for `int`. When called with an `int` argument, the specialized version is used, allowing for type-specific behavior.

Template specialization enhances the flexibility and efficiency of template-based code by allowing fine-tuned implementations for specific types while maintaining the generality of the original template.


### Class Template Specialization Example:

// General template
template <typename T>
class Container {
public:
    void store(T element) {
        std::cout << "Storing a generic element" << std::endl;
    }
};

// Specialization for int
template <>
class Container<int> {
public:
    void store(int element) {
        std::cout << "Storing an integer: " << element << std::endl;
    }
};

// Usage
Container<double> doubleContainer;
doubleContainer.store(3.14);  // Uses general template

Container<int> intContainer;
intContainer.store(42);       // Uses specialized template for int

In this example, we have a general `Container` class template that works for any type, and a specialized version for `int`. The specialized version provides a custom implementation of the `store` method specifically for integers. When used with `int`, the specialized version is instantiated, allowing for type-specific behavior.
