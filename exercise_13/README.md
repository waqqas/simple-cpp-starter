
# Polymorphism in C++

Polymorphism is one of the four fundamental principles of object-oriented programming (OOP) in C++. It allows objects of different classes to be treated as objects of a common base class. The term "polymorphism" comes from Greek, meaning "many forms."

There are two main types of polymorphism in C++:

1. Compile-time Polymorphism (Static Polymorphism):
   - Function Overloading: Multiple functions with the same name but different parameters.
   - Operator Overloading: Giving special meanings to operators for user-defined types.

2. Runtime Polymorphism (Dynamic Polymorphism):
   - Achieved through inheritance and virtual functions.
   - Allows a base class pointer to call the appropriate derived class method.

## Example of Runtime Polymorphism


class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();  // Outputs: Drawing a circle
    shape2->draw();  // Outputs: Drawing a square

    delete shape1;
    delete shape2;

    return 0;
}


In this example, `Shape` is the base class with a virtual function `draw()`. `Circle` and `Square` are derived classes that override the `draw()` function. The program demonstrates how a base class pointer can be used to call the appropriate derived class method at runtime.

Polymorphism enhances code flexibility, reusability, and makes it easier to extend existing code without modifying it (following the Open-Closed Principle).


# Sequence of Constructor Calls in Inheritance

This is an important concept in object-oriented programming, particularly in languages like C++ and Java. Let's break it down step by step:

Base Class Constructor First: When an object of a derived class is created, the constructor of the base class is called first. This ensures that the base class portion of the object is initialized before the derived class-specific initialization occurs.

Derived Class Constructor Second: After the base class constructor completes, the derived class constructor is called. This allows the derived class to initialize its own specific members.

Multiple Inheritance (in languages that support it, like C++): If a class inherits from multiple base classes, the constructors are called in the order in which the base classes are listed in the class declaration.

Virtual Base Classes: In the case of virtual inheritance, the constructor of the virtual base class is called before any non-virtual base classes.

# Sequence of Destructor Calls in Inheritance

The sequence of destructor calls in inheritance is the reverse of constructor calls. This is an important concept in object-oriented programming, particularly in languages like C++ and Java. Here's a detailed explanation:

1. Derived Class Destructor First:
   When an object of a derived class is destroyed, the destructor of the derived class is called first. This allows the derived class to clean up its own specific resources before the base class resources are deallocated.

2. Base Class Destructor Second:
   After the derived class destructor completes, the base class destructor is called. This ensures that the base class portion of the object is properly cleaned up after the derived class-specific cleanup has occurred.

3. Multiple Inheritance (in languages that support it, like C++):
   If a class inherits from multiple base classes, the destructors are called in the reverse order of the base class constructors. This means the destructors are called in the opposite order of how the base classes are listed in the class declaration.

4. Virtual Base Classes:
   In the case of virtual inheritance, the destructor of the virtual base class is called after all non-virtual base classes have been destroyed.

5. Virtual Destructors:
   It's important to note that in languages like C++, the base class destructor should be declared as virtual to ensure proper destruction of derived class objects through base class pointers. This allows the correct destructor to be called based on the actual type of the object, rather than the type of the pointer.

6. Exception Safety:
   The sequence of destructor calls is guaranteed even if an exception is thrown during object destruction. This helps maintain exception safety and proper resource management.

7. Importance in Resource Management:
   This sequence is crucial for proper resource management, especially in languages without automatic garbage collection. It ensures that resources are released in the correct order, preventing memory leaks and other resource-related issues.

8. Implicit Calls:
   Even if not explicitly defined, the compiler will generate implicit destructor calls to ensure this sequence is followed.

Understanding this sequence is essential for writing robust and memory-safe code in object-oriented programming, especially when dealing with inheritance hierarchies and resource management.
