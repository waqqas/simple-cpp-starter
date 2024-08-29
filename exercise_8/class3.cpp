#include <iostream>
#include "car.h"

int main()
{
    std::cout << "main() starts" << std::endl;

    Car *cars[10];

    for (int i = 0; i < 10; i++)
    {
        cars[i] = new Car{"LH "};
    }

    for (Car *car : cars)
    {
        std::cout << "Number plate: " << car->get_number_plate() << std::endl;
    }

    std::cout << "main() ends" << std::endl;

    for (Car *car : cars)
    {
        delete car;
    }

    return 0;
}