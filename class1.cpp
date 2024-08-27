#include <iostream>
#include "cat.h"

using namespace Animal;

int main()
{

    Cat myCat;

    // Call member functions on the Cat object
    myCat.meow();

    std::cout << "Age: " << myCat.get_age() << std::endl;

    return 0;
}