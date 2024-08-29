#include <iostream>
#include "car.h"

int main()
{
    std::cout << "main() starts" << std::endl;

    const char *number_plate = "ABC123";

    Car *car1 = new Car{number_plate};

    std::cout << "Number plate: " << car1->get_number_plate() << std::endl;

    car1->set_number_plate("XYZ789");
    std::cout << "Number plate: " << car1->get_number_plate() << std::endl;

    std::cout << "main() ends" << std::endl;

    delete car1;

    return 0;
}