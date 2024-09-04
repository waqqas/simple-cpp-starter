
# std::tuple

`std::tuple` is a fixed-size collection of heterogeneous values. It is a template class that can hold elements of different types. Tuples are useful when you need to bundle together a few values, possibly of different types, as a single object.

## Basic Usage


#include <tuple>
#include <iostream>
#include <string>

int main() {
    // Creating a tuple
    std::tuple<int, std::string, double> person(30, "John Doe", 5.8);

    // Accessing tuple elements
    std::cout << "Age: " << std::get<0>(person) << std::endl;
    std::cout << "Name: " << std::get<1>(person) << std::endl;
    std::cout << "Height: " << std::get<2>(person) << std::endl;

    return 0;
}


## Creating Tuples

You can create tuples in several ways:


// Using the constructor
std::tuple<int, char, double> t1(10, 'A', 3.14);

// Using std::make_tuple
auto t2 = std::make_tuple(20, 'B', 2.718);

// C++17 class template argument deduction
std::tuple t3(30, 'C', 1.414);


## Accessing Tuple Elements

There are multiple ways to access tuple elements:


std::tuple<int, std::string, bool> t(42, "Hello", true);

// Using std::get with index
std::cout << std::get<0>(t) << std::endl; // 42

// Using std::get with type (if types are unique)
std::cout << std::get<std::string>(t) << std::endl; // "Hello"

// Using C++17 structured bindings
auto [num, str, flag] = t;
std::cout << num << ", " << str << ", " << flag << std::endl;


## Tuple Operations


#include <tuple>

int main() {
    auto t1 = std::make_tuple(1, "two", 3.0);
    auto t2 = std::make_tuple(4, "five", 6.0);

    // Comparing tuples
    bool are_equal = (t1 == t2); // false

    // Concatenating tuples
    auto t3 = std::tuple_cat(t1, t2);

    // Getting the size of a tuple
    constexpr size_t size = std::tuple_size<decltype(t1)>::value; // 3

    return 0;
}


## Use Cases

1. Returning multiple values from a function:


std::tuple<int, int> divide_and_remainder(int dividend, int divisor) {
    return {dividend / divisor, dividend % divisor};
}

int main() {
    auto [quotient, remainder] = divide_and_remainder(10, 3);
    std::cout << "Quotient: " << quotient << ", Remainder: " << remainder << std::endl;
    return 0;
}


2. Grouping heterogeneous data:


std::vector<std::tuple<int, std::string, double>> employees = {
    {1, "Alice", 50000.0},
    {2, "Bob", 55000.0},
    {3, "Charlie", 60000.0}
};

for (const auto& [id, name, salary] : employees) {
    std::cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << std::endl;
}


`std::tuple` provides a flexible way to group multiple values of different types, making it a versatile tool in C++ programming.
