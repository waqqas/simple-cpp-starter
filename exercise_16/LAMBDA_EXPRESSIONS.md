
# Lambda Expressions in C++

Lambda expressions, introduced in C++11, are a concise way to create anonymous function objects. They allow you to write inline functions that can be used for short snippets of code that are not going to be reused and are not worth naming.

## Basic Syntax

The basic syntax of a lambda expression is:


[capture clause](parameters) -> return_type {
    // function body
}


- `[capture clause]`: Specifies which variables from the enclosing scope are accessible within the lambda function body.
- `(parameters)`: Optional. Specifies the parameters of the lambda function.
- `-> return_type`: Optional. Specifies the return type of the lambda function.
- `{function body}`: The actual code of the lambda function.

## Examples

1. Simple lambda expression:


auto greet = []() { std::cout << "Hello, World!" << std::endl; };
greet(); // Outputs: Hello, World!


2. Lambda with parameters:


auto add = [](int a, int b) { return a + b; };
std::cout << add(3, 4); // Outputs: 7


3. Lambda with capture clause:


int x = 10;
auto multiply = [x](int y) { return x * y; };
std::cout << multiply(5); // Outputs: 50


4. Lambda with mutable keyword:

The `mutable` keyword in lambda expressions allows you to modify captured variables within the lambda body, even if they were captured by value. By default, variables captured by value are const inside the lambda. Using `mutable` removes this const-ness.

Example:
```
auto counter = [count = 0]() mutable {
    return ++count;
};

std::cout << counter() << std::endl; // Outputs: 1
std::cout << counter() << std::endl; // Outputs: 2
```

In this example, `count` is captured by value and initialized to 0. The `mutable` keyword allows us to modify `count` within the lambda body, incrementing it each time the lambda is called.

Example:
```
int x = 10;
auto increment = [x]() mutable { return ++x; };
std::cout << increment(); // Outputs: 11
std::cout << x; // Outputs: 10 (original x is unchanged)
```

5. Lambda with generic parameters (C++14):

```
auto print = [](auto x) { std::cout << x << std::endl; };
print(42);    // Outputs: 42
print("Hello"); // Outputs: Hello
```

Lambda expressions are particularly useful in combination with algorithms from the Standard Template Library (STL). They provide a convenient way to customize the behavior of these algorithms without writing separate named functions.

```
std::vector<int> numbers = {1, 2, 3, 4, 5};
std::for_each(numbers.begin(), numbers.end(), [](int n) {
    std::cout << n * n << " ";
});
// Outputs: 1 4 9 16 25
```

Lambda expressions in C++ offer a powerful and flexible way to write inline functions, making your code more readable and maintainable.
