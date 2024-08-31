#pragma once

#include "vehicle.h"

class Truck : public Vehicle
{
private:
    int num_axles;
    int cargo_capacity;
    int num_wheels;

public:
    Truck()
    {
        std::cout << this << ": Truck constructor called: " << std::endl;
    }

    ~Truck()
    {
        std::cout << this << ": Truck destructor called: " << std::endl;
    }

    void print() override
    {
        Vehicle::print();
        std::cout << "Truck with " << num_axles << " axles, " << cargo_capacity << " lbs of cargo capacity, and " << num_wheels << " wheels" << std::endl;
    }
};