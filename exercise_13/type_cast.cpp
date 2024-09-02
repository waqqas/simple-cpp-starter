
#include <iostream>

int main()
{
    // C-style cast
    int intValue = 10;
    double doubleValue = (double)intValue;
    std::cout << "C-style cast: " << doubleValue << std::endl;

    // static_cast
    float floatValue = 3.14f;
    int roundedValue = static_cast<int>(floatValue);
    std::cout << "static_cast: " << roundedValue << std::endl;

    // dynamic_cast (requires polymorphic types)
    class Base
    {
    public:
        virtual ~Base() {}
    };
    class Derived : public Base
    {
    };
    Base *basePtr = new Derived();
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
    std::cout << "dynamic_cast: " << (derivedPtr != nullptr ? "Successful" : "Failed") << std::endl;
    delete basePtr;

    // const_cast
    const int constValue = 5;
    int *nonConstPtr = const_cast<int *>(&constValue);
    std::cout << "const_cast: " << *nonConstPtr << std::endl;

    // reinterpret_cast
    int integerValue = 42;
    int *intPtr = &integerValue;
    long longValue = reinterpret_cast<long>(intPtr);
    std::cout << "reinterpret_cast: " << longValue << std::endl;

    return 0;
}
