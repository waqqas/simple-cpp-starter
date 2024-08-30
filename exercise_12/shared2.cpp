#include <iostream>
#include <memory>
#include "car.h"

int main()
{
    Car car1{"ABC123"};
    Car car2{car1};
    Car car3;
    car3 = car2;

    std::cout << "car1:" << car1.get_number_plate() << std::endl;
    std::cout << "car2:" << car2.get_number_plate() << std::endl;
    std::cout << "car3:" << car3.get_number_plate() << std::endl;

    return 0;
}