#include <iostream>
#include "cat.h"

namespace Animal::Mammal
{
    Cat::Cat()
    {
        // Implementation of constructor
    }

    Cat::~Cat()
    {
        // Implementation of destructor
    }
    void Cat::meow()
    {
        std::cout << "Meow!" << std::endl;
    }
} // namespace Animal::Mammal
