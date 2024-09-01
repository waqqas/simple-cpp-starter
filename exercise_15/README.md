
# std::numeric_limits

`std::numeric_limits` is a class template in C++ that provides information about the properties and limitations of arithmetic types. It is part of the `<limits>` header and offers a standardized way to query various characteristics of numeric types.

## Key Features

- Provides compile-time constants for type-specific properties
- Works with built-in arithmetic types and user-defined types
- Offers a consistent interface across different types

## Common Member Functions and Constants

- `min()`: Returns the minimum finite value
- `max()`: Returns the maximum finite value
- `lowest()`: Returns the lowest finite value (same as `min()` for integer types)
- `epsilon()`: Returns the difference between 1 and the next representable value (for floating-point types)
- `is_integer`: Boolean indicating whether the type is integer
- `is_signed`: Boolean indicating whether the type is signed
- `digits`: Number of radix digits that can be represented without change
- `is_exact`: Boolean indicating whether the type uses exact representation

## Usage Example


#include <iostream>
#include <limits>
#include <cmath>

int main() {
    // Integer limits
    std::cout << "Int max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Int min: " << std::numeric_limits<int>::min() << std::endl;

    // Floating-point limits
    std::cout << "Float epsilon: " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "Double lowest: " << std::numeric_limits<double>::lowest() << std::endl;

    // Type properties
    std::cout << "Is int signed? " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "Digits in double: " << std::numeric_limits<double>::digits << std::endl;

    return 0;
}


This example demonstrates how to use `std::numeric_limits` to query various properties of integer and floating-point types. It's particularly useful when writing generic code or when you need to know the exact limitations of a specific type on your platform.
