
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

```
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage
int maxInt = max(10, 20);        // Works with integers
double maxDouble = max(3.14, 2.71);  // Works with doubles
```

In this exercise, you'll practice creating and using basic function and class templates to understand how they work and their benefits in C++ programming.



## Template Specialization

Template specialization is a feature in C++ that allows you to provide a specific implementation of a template for a particular data type. This is useful when you want to optimize or customize the behavior of a template for a specific type.

### Key points:
- Allows for type-specific optimizations or implementations
- Can be applied to both function and class templates
- Syntax: `template <> returnType functionName<SpecificType>(SpecificType parameter) { ... }`

### Example:

```
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
```

In this example, the `print` function has a general template that works for any type, but a specialized version is provided for `int`. When called with an `int` argument, the specialized version is used, allowing for type-specific behavior.

Template specialization enhances the flexibility and efficiency of template-based code by allowing fine-tuned implementations for specific types while maintaining the generality of the original template.


### Class Template Specialization Example:
```
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
```

In this example, we have a general `Container` class template that works for any type, and a specialized version for `int`. The specialized version provides a custom implementation of the `store` method specifically for integers. When used with `int`, the specialized version is instantiated, allowing for type-specific behavior.


### Types of Template Parameters

C++ templates support different types of parameters, allowing for flexible and powerful generic programming. Here are the main types of template parameters:

1. Type Parameters:
   - Syntax: `template <typename T>` or `template <class T>`
   - Example:

```     
     template <typename T>
     T add(T a, T b) {
         return a + b;
     }
```     

2. Non-Type Parameters:
   - These are compile-time constants of integral or pointer type.
   - Syntax: `template <type-name non-type-parameter>`
   - Example:

```     
     template <int N>
     class Array {
         int data[N];
     };
```     

3. Template Template Parameters:
   - These are themselves templates.
   - Syntax: `template <template <typename> class ContainerType>`
   - Example:

```     
     template <template <typename> class Container, typename T>
     class Wrapper {
         Container<T> data;
     };
```     

4. Variadic Templates:
   - Allow a variable number of template arguments.
   - Syntax: `template <typename... Args>`
   - Example:

```     
     template <typename... Args>
     void printAll(Args... args) {
         (std::cout << ... << args) << std::endl;
     }
```     

5. Default Template Parameters:
   - Provide default values for template parameters.
   - Syntax: `template <typename T = int>`
   - Example:
     
```     
     template <typename T = int>
     class MyClass {
         T value;
     };
```     

These different types of template parameters provide flexibility in creating generic code that can work with various types and configurations, enhancing code reusability and maintainability.

6. Using decltype in C++ Templates:
   - decltype is used to deduce the type of an expression at compile-time.
   - It's particularly useful in templates when the return type depends on template parameters.
   - Syntax: `decltype(expression)`
   - Example:

```
     template<typename T, typename U>
     auto add(T t, U u) -> decltype(t + u) {
         return t + u;
     }
```

   - In this example, decltype(t + u) deduces the return type based on the result of t + u.
   - It's often used with trailing return type syntax (->).

   Another example using decltype to deduce a member type:

```
     template<typename T>
     class Container {
     public:
         using value_type = T;
         value_type getValue() { return value; }
     private:
         T value;
     };

     template<typename T>
     auto getContainerValue(Container<T>& c) -> decltype(c.getValue()) {
         return c.getValue();
     }
```

   Here, decltype(c.getValue()) deduces the return type of the getValue() method.

   decltype can also be used in template parameter deduction:

```
     template<typename Container, typename Index>
     auto accessElement(Container& c, Index i) -> decltype(c[i]) {
         return c[i];
     }
```

   In this case, decltype(c[i]) deduces the return type of the container's operator[].

Using decltype in templates allows for more flexible and generic code, especially when dealing with complex types or when the exact type is not known in advance.


7. Combining Inheritance with Class Templates:
   - Class templates can be used as base classes or derived classes in inheritance hierarchies.
   - This allows for creating flexible and reusable code structures.
   - Example:

```
// Base template class
template<typename T>
class Base {
protected:
    T value;
public:
    Base(T val) : value(val) {}
    virtual void display() {
        std::cout << "Base value: " << value << std::endl;
    }
};

// Derived template class inheriting from Base
template<typename T, typename U>
class Derived : public Base<T> {
private:
    U extra;
public:
    Derived(T val, U ext) : Base<T>(val), extra(ext) {}
    void display() override {
        Base<T>::display();
        std::cout << "Derived extra: " << extra << std::endl;
    }
};

// Usage example
int main() {
    Derived<int, std::string> d(10, "Hello");
    d.display();
    return 0;
}
```

   In this example:
   - `Base<T>` is a template base class with a single type parameter.
   - `Derived<T, U>` is a template derived class that inherits from `Base<T>` and adds an extra parameter `U`.
   - The derived class can access and extend the functionality of the base class.
   - This approach allows for creating complex hierarchies with type-safe inheritance.

   Benefits:
   - Reusability: Template base classes can be reused with different type parameters.
   - Flexibility: Derived classes can add their own type parameters and functionality.
   - Type safety: The compiler ensures type consistency throughout the inheritance hierarchy.

   Note: When using virtual functions in template classes, remember that each instantiation of the template creates a separate class, so virtual function tables are generated for each type used.

Automatic type inference for templates, also known as template argument deduction, is a feature in C++ that allows the compiler to automatically deduce the types of template arguments based on the function arguments provided. This happens in the following ways:

1. Function template argument deduction:

```
template<typename T>
void printValue(T value) {
    std::cout << value << std::endl;
}

int main() {
    printValue(42);       // T is deduced as int
    printValue(3.14);     // T is deduced as double
    printValue("Hello");  // T is deduced as const char*
    return 0;
}
```

2. Class template argument deduction (CTAD) - introduced in C++17:

```
template<typename T>
class Container {
public:
    Container(T value) : data(value) {}
private:
    T data;
};

int main() {
    Container c1(42);     // Container<int>
    Container c2(3.14);   // Container<double>
    Container c3("Hello"); // Container<const char*>
    return 0;
}
```

3. Auto keyword for variables:

```
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

int main() {
    auto result1 = add(5, 3);      // result1 is int
    auto result2 = add(5.0, 3);    // result2 is double
    auto result3 = add(5, 3.0);    // result3 is double
    return 0;
}
```

4. Lambda expressions with auto parameters (C++14 and later):

```
auto lambda = [](auto x, auto y) {
    return x + y;
};

int main() {
    auto result1 = lambda(5, 3);      // int + int
    auto result2 = lambda(5.0, 3);    // double + int
    auto result3 = lambda(5, 3.0);    // int + double
    return 0;
}
```

These mechanisms allow for more concise and flexible code, as the compiler can infer the types based on the context and usage, reducing the need for explicit type specifications in many cases.
