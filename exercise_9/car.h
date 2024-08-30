#pragma once

#include <iostream>
#include <string.h>

class Car
{
private:
    char *number_plate = nullptr;

public:
    Car() : Car("")
    {
        std::cout << "Car constructor called: " << std::endl;
    }

    Car(const char *new_number_plate)
    {
        std::cout << "Car delegating constructor called: " << std::endl;

        set_number_plate(new_number_plate);
    }

    Car(const Car &other)
    {
        std::cout << "Copy constructor called: " << std::endl;

        set_number_plate(other.number_plate);
    }

    Car(Car &&other) noexcept
    {
        std::cout << "Move constructor called: " << std::endl;
        number_plate = std::move(other.number_plate);
        other.number_plate = nullptr;
    }

    // Car(Car &&other) noexcept = default;

    ~Car()
    {
        std::cout << "Car destructor called: " << std::endl;
        delete[] number_plate;
        number_plate = nullptr;
    }

    void set_number_plate(const char *new_number_plate)
    {
        delete[] number_plate;
        size_t input_length = strlen(new_number_plate);
        number_plate = new char[input_length + 1];
        strncpy(number_plate, new_number_plate, input_length);
        number_plate[input_length] = '\0';
    }

    const char *get_number_plate() const
    {
        return number_plate;
    }
};