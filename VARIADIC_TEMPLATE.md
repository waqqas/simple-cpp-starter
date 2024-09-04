
# Variadic Templates in C++

Variadic templates are a feature in C++ that allow you to define templates that can take any number of arguments. This is particularly useful when you want to create functions or classes that can work with a variable number of parameters of different types.

## Basic Example: Variadic Function Template


#include <iostream>

// Base case: when there are no more arguments
void print() {
    std::cout << std::endl;
}

// Variadic template function
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "Hello", 'c');
    return 0;
}


In this example, `print` is a variadic function template that can take any number of arguments of any type. It prints each argument followed by a space, then recursively calls itself with the remaining arguments.

## Variadic Class Template


#include <iostream>
#include <tuple>

template<typename... Types>
class Tuple {
private:
    std::tuple<Types...> data;

public:
    Tuple(Types... args) : data(args...) {}

    template<size_t I>
    auto get() {
        return std::get<I>(data);
    }

    void printTypes() {
        printTypesHelper(std::index_sequence_for<Types...>{});
    }

private:
    template<size_t... Is>
    void printTypesHelper(std::index_sequence<Is...>) {
        ((std::cout << typeid(std::tuple_element_t<Is, std::tuple<Types...>>).name() << " "), ...);
        std::cout << std::endl;
    }
};

int main() {
    Tuple<int, double, std::string> t(1, 2.5, "Hello");
    std::cout << "First element: " << t.get<0>() << std::endl;
    std::cout << "Types in tuple: ";
    t.printTypes();
    return 0;
}


This example demonstrates a variadic class template `Tuple` that can hold any number of elements of different types. It uses `std::tuple` internally and provides methods to access elements and print their types.

## Variadic Template for Summing Numbers


#include <iostream>

// Base case: sum of zero elements is 0
template<typename T>
T sum(T t) {
    return t;
}

// Recursive case: sum current element with sum of rest
template<typename T, typename... Rest>
T sum(T first, Rest... rest) {
    return first + sum(rest...);
}

int main() {
    std::cout << "Sum: " << sum(1, 2, 3, 4, 5) << std::endl;
    std::cout << "Sum: " << sum(1.5, 2.7, 3.2) << std::endl;
    return 0;
}


This example shows how to use variadic templates to create a function that can sum any number of arguments of the same type.

These examples demonstrate the flexibility and power of variadic templates in C++, allowing you to write more generic and reusable code.
