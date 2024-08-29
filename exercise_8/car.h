#pragma once

#include <iostream>
#include <string.h>

class Car
{
private:
    char number_plate[20];

public:
    Car()
    {
        std::cout << "Car constructor called" << std::endl;
    }
    ~Car()
    {
        std::cout << "Car destructor called" << std::endl;
    }

    void set_number_plate(char *new_number_plate)
    {
        strncpy(number_plate, new_number_plate, sizeof(number_plate) - 1);
    }

    char *get_number_plate()
    {
        return number_plate;
    }
};