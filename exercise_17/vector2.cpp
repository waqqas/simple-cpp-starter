#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(i);
        std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;
    }

    return 0;
}