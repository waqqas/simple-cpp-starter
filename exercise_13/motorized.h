#pragma once
#include <iostream>
#include "engine.h"

class Motorized
{
private:
    Engine engine;

public:
    Motorized()
    {
        std::cout << this << ": Motorized constructor called: " << std::endl;
    }
    ~Motorized()
    {
        std::cout << this << ": Motorized destructor called: " << std::endl;
    }

    void print()
    {
        std::cout << "Motorized: Engine: " << engine << std::endl;
    }
};