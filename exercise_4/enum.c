#include <stdio.h>

// Define an enum for days of the week
enum Days
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    // Declare a variable of type enum Days
    enum Days today;

    // Assign a value from the enum to the variable
    today = WEDNESDAY;

    // Print the value of the variable
    printf("Today is day number %d\n", today);

    return 0;
}