#include <iostream>

template <typename T, int SIZE>
class Garage
{
private:
    T *vehicles[SIZE] = {nullptr};
    int capacity = SIZE;
    int count = 0;

public:
    void add_vehicle(const T &vehicle)
    {
        if (count < capacity)
        {
            vehicles[count++] = vehicle;
        }
        else
        {
            std::cout << "Garage is full. Cannot add more vehicles." << std::endl;
        }
    }

    void remove_vehicle()
    {
        if (count > 0)
        {
            --count;
        }
        else
        {
            std::cout << "Garage is empty. No vehicles to remove." << std::endl;
        }
    }

    void display_vehicles() const
    {
        if (count == 0)
        {
            std::cout << "Garage is empty." << std::endl;
        }
        else
        {
            std::cout << "Vehicles in the garage:" << std::endl;
            for (int i = 0; i < count; ++i)
            {
                std::cout << vehicles[i] << std::endl;
            }
        }
    }

    int get_count() const
    {
        return count;
    }
};