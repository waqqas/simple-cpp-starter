#include <iostream>
#include "car.h"

int main()
{
    Car car1;
    Car car2{car1};
    Car car3 = car2;

    return 0;
}