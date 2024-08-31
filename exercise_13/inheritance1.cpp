#include <iostream>
#include <memory>
#include "car.h"

using VehiclePtr = std::shared_ptr<Vehicle>;

int main()
{
    VehiclePtr car1 = std::make_shared<Car>();

    car1->print();

    return 0;
}