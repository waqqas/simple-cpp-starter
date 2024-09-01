#include <iostream>
#include "garage.h"
#include "car.h"
#include "truck.h"
#include "motorcycle.h"

typedef Garage<Car, 5> CarGarage;
typedef Garage<Truck, 10> TruckGarage;
typedef Garage<Motorcycle, 15> MotorcycleGarage;
typedef Garage<Vehicle, 20> VehicleGarage;

int main()
{
    CarGarage car_garage;
    TruckGarage big_truck_garage;
    VehicleGarage vehicle_garage;

    return 0;
}