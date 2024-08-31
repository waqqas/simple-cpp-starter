#pragma once

#include <iostream>

class Vehicle
{
private:
    int id;
    std::string make;
    std::string model;

public:
    Vehicle()
    {
        std::cout << this << ": Vehicle constructor called: " << std::endl;
    }

    ~Vehicle()
    {
        std::cout << this << ": Vehicle destructor called: " << std::endl;
    }

    virtual void print()
    {
        std::cout << "Vehicle ID: " << id << std::endl
                  << "Make: " << make << std::endl
                  << "Model: " << model << std::endl;
    }
};
