
#include <iostream>
#include <memory>

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
    void use() { std::cout << "Resource used\n"; }
};

int main()
{
    // Create a shared_ptr
    auto sharedResource = std::make_shared<Resource>();

    // Create a weak_ptr from the shared_ptr
    std::weak_ptr<Resource> weakResource = sharedResource;

    // Use the weak_ptr
    if (auto tempShared = weakResource.lock())
    {
        std::cout << "Resource still alive\n";
        tempShared->use();
    }
    else
    {
        std::cout << "Resource no longer available\n";
    }

    // Reset the shared_ptr
    sharedResource.reset();

    // Try to use the weak_ptr again
    if (auto tempShared = weakResource.lock())
    {
        std::cout << "Resource still alive\n";
        tempShared->use();
    }
    else
    {
        std::cout << "Resource no longer available\n";
    }

    return 0;
}
