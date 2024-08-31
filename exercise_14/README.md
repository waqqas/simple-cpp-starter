
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
