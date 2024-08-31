#pragma once

#include <iostream>

class Engine
{
private:
    int num_cylinders;

public:
    Engine()
    {
        std::cout << this << ": Engine constructor called: " << std::endl;
    }
    ~Engine()
    {
        std::cout << this << ": Engine destructor called: " << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const Engine &engine)
    {
        os << "Engine with " << engine.num_cylinders << " cylinders";
        return os;
    }
};