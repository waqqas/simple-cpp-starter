#pragma once

#include "vehicle.h"

class Car : public Vehicle
{
private:
    int num_doors;
    int num_seats;
    int num_wheels;

public:
    Car()
    {
        std::cout << this << ": Car constructor called: " << std::endl;
    }

    ~Car()
    {
        std::cout << this << ": Car destructor called: " << std::endl;
    }

    void print() override
    {
        Vehicle::print();
        std::cout << "Car with " << num_doors << " doors, " << num_seats << " seats, and " << num_wheels << " wheels" << std::endl;
    }
};