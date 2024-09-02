
#include <iostream>
#include <memory>

class B;

class A
{
public:
    std::shared_ptr<B> b_ptr;
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destructed\n"; }
};

class B
{
public:
    std::weak_ptr<A> a_ptr; // Using weak_ptr to break circular dependency
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destructed\n"; }
};

int main()
{
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();

        a->b_ptr = b;
        b->a_ptr = a;

        std::cout << "a use count: " << a.use_count() << std::endl;
        std::cout << "b use count: " << b.use_count() << std::endl;
    }

    std::cout << "End of scope\n";
    return 0;
}
