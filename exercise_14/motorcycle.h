#pragma once
#include <iostream>
#include "vehicle.h"

class Motorcycle : public Vehicle
{
private:
    int num_wheels;
    int num_seats;

public:
    Motorcycle()
    {
        std::cout << this << ": Motorcycle constructor called: " << std::endl;
    }
    ~Motorcycle()
    {
        std::cout << this << ": Motorcycle destructor called: " << std::endl;
    }
    void print() override
    {
        std::cout << "Motorcycle with " << num_wheels << " wheels and " << num_seats << " seats" << std::endl;
    }
};