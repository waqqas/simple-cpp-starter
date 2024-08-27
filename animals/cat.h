#ifndef CAT_H
#define CAT_H

namespace Animal
{
    class Cat
    {
    public:
        Cat();  // Constructor
        ~Cat(); // Destructor

        void meow() const;         // Member function
        void set_age(int new_age); // Member function
        int get_age() const;       // Member function

    private:
        // Private members (if any)
        int age;
    };

}

#endif