#include <iostream>
#include "car.h"

Car make_car()
{
    Car car{};
    std::cout << "Local car:  " << &car << std::endl;
    return car;
}

int main()
{
    Car car1;
    car1 = make_car();
    std::cout << "Car1: " << &car1 << std::endl;
    return 0;
}