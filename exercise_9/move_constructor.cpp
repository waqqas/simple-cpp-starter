#include <iostream>
#include "car.h"

int main()
{
    Car car1;
    Car car2(std::move(car1));

    return 0;
}