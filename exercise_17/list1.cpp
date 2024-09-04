
#include <iostream>
#include <list>

int main()
{
    std::list<int> myList = {3, 1, 4, 1, 5, 9};

    myList.push_front(0);
    myList.push_back(2);

    for (const auto &elem : myList)
    {
        std::cout << elem << " ";
    }
    // Output: 0 3 1 4 1 5 9 2

    return 0;
}
