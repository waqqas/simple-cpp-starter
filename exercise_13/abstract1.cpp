#include <iostream>

// Abstract base class
class Shape
{
public:
    // Pure virtual function (makes the class abstract)
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() {}

    // Non-virtual function
    void printArea() const
    {
        std::cout << "Area: " << area() << std::endl;
    }
};

// Derived class
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementation of the pure virtual function
    double area() const override
    {
        return 3.14159 * radius * radius;
    }
};

// Another derived class
class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementation of the pure virtual function
    double area() const override
    {
        return width * height;
    }
};

int main()
{
    // Shape shape; // This would cause a compilation error

    Circle circle(5);
    Rectangle rectangle(4, 6);

    Shape *shapes[] = {&circle, &rectangle};

    for (const auto &shape : shapes)
    {
        shape->printArea();
    }

    return 0;
}