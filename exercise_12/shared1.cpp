#include <iostream>
#include <memory>
#include <string>

int main()
{
    char *data = new char[10];
    std::shared_ptr<char[]> ptr1{data};
    std::shared_ptr<char[]> ptr2 = ptr1;

    // ptr2 = ptr1;

    std::cout << "ptr1:" << ptr1.use_count() << std::endl;
    std::cout << "ptr2:" << ptr2.use_count() << std::endl;

    return 0;
}