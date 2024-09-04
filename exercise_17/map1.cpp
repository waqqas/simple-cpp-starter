#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> ages = {{"Charlie", 35}, {"Bob", 30}, {"Alice", 25}};

    // Using iterator to access key-value pairs
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
    {
        std::cout << it->first << " is " << it->second << " years old." << std::endl;
    }

    std::cout << std::endl;

    // Using range-based for loop to access key-value pairs
    for (const auto &pair : ages)
    {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
