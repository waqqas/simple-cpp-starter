#pragma once

#include "vehicle.h"
#include "motorized.h"

class Car : public Vehicle, public Motorized
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
        Motorized::print();
        std::cout << "Car with " << num_doors << " doors, " << num_seats << " seats, and " << num_wheels << " wheels" << std::endl;
    }
};