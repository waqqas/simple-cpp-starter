#include <iostream>
#include "my_code.h"
// #include "lib_code.h"        // uncomment this to see the error and then fix it

int main()
{
    printMessage(); // this should print "Hello from MyNamespace!"
    // printMessage();     // this shoud print "Hello from SomeLibNamespace!"

    return 0;
}