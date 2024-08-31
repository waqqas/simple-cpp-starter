#include <iostream>

template <typename T>
class Garage
{
private:
    T *vehicles;
    int capacity;
    int count;

public:
    Garage(int size = 10) : capacity(size), count(0)
    {
        vehicles = new T[capacity];
    }

    // Copy constructor
    Garage(const Garage &other) : capacity(other.capacity), count(other.count)
    {
        vehicles = new T[capacity];
        for (int i = 0; i < count; ++i)
        {
            vehicles[i] = other.vehicles[i];
        }
    }

    // Move constructor
    Garage(Garage &&other) noexcept : vehicles(other.vehicles), capacity(other.capacity), count(other.count)
    {
        other.vehicles = nullptr;
        other.capacity = 0;
        other.count = 0;
    }

    // Copy assignment operator
    Garage &operator=(const Garage &other)
    {
        if (this != &other)
        {
            delete[] vehicles;
            capacity = other.capacity;
            count = other.count;
            vehicles = new T[capacity];
            for (int i = 0; i < count; ++i)
            {
                vehicles[i] = other.vehicles[i];
            }
        }
        return *this;
    }

    // Move assignment operator
    Garage &operator=(Garage &&other) noexcept
    {
        if (this != &other)
        {
            delete[] vehicles;
            vehicles = other.vehicles;
            capacity = other.capacity;
            count = other.count;
            other.vehicles = nullptr;
            other.capacity = 0;
            other.count = 0;
        }
        return *this;
    }

    ~Garage()
    {
        delete[] vehicles;
    }

    void addVehicle(const T &vehicle)
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

    void removeVehicle()
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

    void displayVehicles() const
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

    int getCount() const
    {
        return count;
    }
};
