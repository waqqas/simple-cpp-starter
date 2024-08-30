#pragma once

#include <iostream>
#include <string>
#include <memory>

class Car
{
private:
    std::shared_ptr<std::string> number_plate;

public:
    Car() : Car("")
    {
        std::cout << this << ": Car constructor called: " << std::endl;
    }

    Car(const char *new_number_plate)
    {
        std::cout << this << ": Car delegating constructor called: " << std::endl;
        number_plate = std::make_shared<std::string>(new_number_plate);
    }

    Car(const Car &other)
    {
        std::cout << this << " < " << &other << ": Copy constructor called: " << std::endl;
        number_plate = other.number_plate;
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
            number_plate = other.number_plate;
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

    const std::string &get_number_plate() const
    {
        return *number_plate;
    }
};