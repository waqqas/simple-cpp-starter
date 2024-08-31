#include <iostream>
#include "garage.h"
#include "car.h"
#include "truck.h"

typedef Garage<Car> CarGarage;
typedef Garage<Truck> TruckGarage;

int main()
{
    CarGarage garage{5};
    TruckGarage big_truck_garage{10};

    return 0;
}