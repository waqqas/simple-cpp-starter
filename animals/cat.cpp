#include <iostream>
#include "cat.h"

namespace Animal
{
    Cat::Cat() : age{2}
    {
        // Implementation of constructor
    }

    Cat::~Cat()
    {
        // Implementation of destructor
    }
    void Cat::meow() const
    {
        std::cout << "Meow!" << std::endl;
    }
    void Cat::set_age(int new_age)
    {
        age = new_age;
    }
    int Cat::get_age() const
    {
        return age;
    }
} // namespace Animal
