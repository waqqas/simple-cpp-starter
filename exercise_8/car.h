#pragma once

#include <iostream>
#include <string.h>

class Car
{
private:
    char number_plate[20];
    static int counter;

public:
    Car() : Car("")
    {
        std::cout << "1 Car constructor called: " << std::endl;
    }

    Car(const char *new_number_plate)
    {
        std::cout << "2 Car constructor called: " << std::endl;
        snprintf(number_plate, sizeof(number_plate) - 1, "%s:%d", new_number_plate, counter);
        counter++;
        // strncpy(new_number_plate, "abc", sizeof(new_number_plate) - 1);
        // new_number_plate = nullptr;
    }

    ~Car()
    {
        std::cout << "Car destructor called: " << std::endl;
    }

    void set_number_plate(const char *new_number_plate)
    {
        strncpy(this->number_plate, new_number_plate, sizeof(this->number_plate) - 1);
    }

    const char *get_number_plate() const
    {
        return number_plate;
    }
};