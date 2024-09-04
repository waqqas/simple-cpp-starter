
# Exception Handling in C++

Exception handling in C++ provides a way to deal with runtime errors or exceptional situations that may occur during program execution. It allows you to separate error-handling code from the main logic of your program, making it more readable and maintainable.

## Key Components

1. **try**: A block of code that may throw an exception.
2. **catch**: A block of code that handles a specific type of exception.
3. **throw**: A keyword used to raise an exception.

## Basic Syntax

```
try {
    // Code that may throw an exception
    // ...
    if (someErrorCondition) {
        throw SomeExceptionType("Error message");
    }
}
catch (SomeExceptionType& e) {
    // Handle the specific exception
    std::cerr << "Caught exception: " << e.what() << std::endl;
}
catch (...) {
    // Catch-all handler for any other exceptions
    std::cerr << "Caught unknown exception" << std::endl;
}
```

## Explanation

1. **try block**: 
   - Encloses the code that might throw an exception.
   - If an exception occurs within this block, the program immediately jumps to the appropriate catch block.

2. **catch block**:
   - Handles specific types of exceptions.
   - Can have multiple catch blocks for different exception types.
   - The catch-all handler `catch (...)` can be used to catch any unhandled exceptions.

3. **throw statement**:
   - Used to raise an exception explicitly.
   - Can throw objects of built-in types or user-defined exception classes.

## Example

```
#include <iostream>
#include <stdexcept>

double divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(10, 2) << std::endl; // OK
        std::cout << divide(10, 0) << std::endl; // This will throw an exception
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```

In this example, the `divide` function throws a `std::runtime_error` if division by zero is attempted. The `main` function uses a try-catch block to handle this exception and print an error message.

Exception handling in C++ allows for more robust and error-resistant code, helping to manage and recover from unexpected situations during program execution.


## Creating and Handling Custom Exceptions

To create custom exceptions in C++, you can define your own exception classes that inherit from `std::exception` or one of its derived classes. Here's how to create and handle custom exceptions:

1. **Define a custom exception class**:

```
#include <exception>
#include <string>

class CustomException : public std::exception {
private:
    std::string message;

public:
    explicit CustomException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
```

2. **Throw the custom exception**:

```
void riskyFunction(int value) {
    if (value < 0) {
        throw CustomException("Negative value not allowed");
    }
    // Rest of the function...
}
```

3. **Handle the custom exception**:
```

#include <iostream>

int main() {
    try {
        riskyFunction(-5);
    }
    catch (const CustomException& e) {
        std::cerr << "Caught custom exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Caught unknown exception" << std::endl;
    }

    return 0;
}
```

This example demonstrates:
- Creating a custom exception class `CustomException` derived from `std::exception`.
- Overriding the `what()` function to provide a custom error message.
- Throwing the custom exception in a function.
- Handling the custom exception in a try-catch block, along with standard exceptions and a catch-all handler.

By creating custom exceptions, you can provide more specific error information and handle different error scenarios in a more granular way.



The `explicit` keyword in C++ is used in constructor declarations to prevent implicit type conversions. When a constructor is marked as `explicit`, it cannot be used for implicit conversions and copy-initialization.

Here's an example to illustrate the use of `explicit`:


class MyClass {
public:
    explicit MyClass(int x) : value(x) {}
    int getValue() const { return value; }
private:
    int value;
};

int main() {
    MyClass obj1(10);  // Direct initialization, OK
    MyClass obj2 = 20; // Copy initialization, Error: explicit constructor
    MyClass obj3 = MyClass(30); // OK, direct initialization

    // Error: no implicit conversion
    // void takeMyClass(MyClass mc);
    // takeMyClass(40);

    return 0;
}


Benefits of using `explicit`:
1. Prevents unintended implicit conversions
2. Makes the code more readable and less prone to errors
3. Enforces stricter type checking

Use `explicit` when you want to ensure that objects of your class are created only through direct initialization or explicit type conversion.
