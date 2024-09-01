#include <iostream>

// Define an enum class for days of the week
enum class Days
{
    MONDAY = 10,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    // Declare a variable of type enum class Days
    Days today;

    // Assign a value from the enum class to the variable
    today = Days::WEDNESDAY;

    // Print the value of the variable
    std::cout << "Today is: " << (int)today << std::endl;

    return 0;
}