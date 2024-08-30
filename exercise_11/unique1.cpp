#include <iostream>
#include <memory>

int main()
{
    int *data = new int[10];

    std::unique_ptr<int> ptr1{data};
    std::unique_ptr<int> ptr2;

    ptr2 = std::move(ptr1);

    return 0;
}