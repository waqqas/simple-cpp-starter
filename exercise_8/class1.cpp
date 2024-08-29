#include <iostream>
#include "car.h"

int main()
{
    std::cout << "main() starts" << std::endl;

    char number_plate[20] = "ABC123";

    Car car1{number_plate};

    std::cout << "Number plate: " << car1.get_number_plate() << std::endl;

    car1.set_number_plate("XYZ789");
    std::cout << "Number plate: " << car1.get_number_plate() << std::endl;

    std::cout << "main() ends" << std::endl;

    return 0;
}