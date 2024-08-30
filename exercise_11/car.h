#pragma once

#include <iostream>
#include <string.h>
#include <memory>
#include "memory.h"

class Car
{
private:
    std::unique_ptr<char[]> number_plate;

public:
    Car() : Car("")
    {
        std::cout << this << ": Car constructor called: " << std::endl;
    }

    Car(const char new_number_plate[])
    {
        std::cout << this << ": Car delegating constructor called: " << std::endl;

        set_number_plate(new_number_plate);
    }

    Car(const Car &other)
    {
        std::cout << this << " < " << &other << ": Copy constructor called: " << std::endl;

        set_number_plate(other.number_plate.get());
    }

    Car(Car &&other) noexcept
    {
        std::cout << this << " < " << &other << ": Move constructor called: " << std::endl;
        number_plate = std::move(other.number_plate);
    }

    Car &operator=(const Car &other)
    {
        std::cout << this << " < " << &other << ": Copy assignment operator called: " << std::endl;
        if (this != &other)
        {
            set_number_plate(other.number_plate.get());
        }
        return *this;
    }

    Car &operator=(Car &&other) noexcept
    {
        std::cout << this << " < " << &other << ": Move assignment operator called: " << std::endl;
        if (this != &other)
        {
            number_plate = std::move(other.number_plate);
        }
        return *this;
    }

    ~Car()
    {
        std::cout << this << ": Car destructor called: " << std::endl;
    }

    void set_number_plate(const char new_number_plate[])
    {
        size_t input_length = strlen(new_number_plate);
        number_plate = std::make_unique<char[]>(input_length + 1);
        strncpy(number_plate.get(), new_number_plate, input_length);
        number_plate[input_length] = '\0';
    }

    const char *get_number_plate() const
    {
        return number_plate.get();
    }
};