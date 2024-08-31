
# Operator Overloading in C++

Operator overloading is a feature in C++ that allows you to define custom behaviors for operators when they are used with user-defined types (classes or structures). This enables you to make your classes work more intuitively with built-in operators.

## Basic Syntax

To overload an operator, you define a special member function or a global function with the following syntax:


return_type operator symbol(parameters) {
    // Implementation
}


Where:
- `return_type` is the type returned by the operator
- `symbol` is the operator being overloaded (e.g., +, -, *, /, etc.)
- `parameters` are the operands involved in the operation

## Examples

### Overloading the Addition Operator (+)


class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};


### Overloading the Stream Insertion Operator (<<)


class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& n, int a) : name(n), age(a) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << p.name << " (" << p.age << " years old)";
        return os;
    }
};


## Guidelines for Operator Overloading

1. Maintain the original meaning of the operator
2. Preserve the operator's precedence and associativity
3. Avoid unexpected side effects
4. Consider overloading related operators together (e.g., + and +=)
5. Use member functions for operators that modify the object's state
6. Use non-member functions for symmetric operators or when the left operand is not of the class type

## Operators That Cannot Be Overloaded

Some operators in C++ cannot be overloaded:
- Scope resolution operator (::)
- Member selection operator (.)
- Member selection through pointer operator (->*)
- Ternary conditional operator (?:)

Operator overloading, when used judiciously, can make your code more readable and intuitive. However, it's important to use this feature responsibly to avoid confusion and maintain code clarity.
