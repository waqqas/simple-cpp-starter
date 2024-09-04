#include <fstream>
#include <iostream>
#include <string>

class Person
{
public:
    std::string name;
    int age;

    Person() : name(""), age(0) {}
    Person(const std::string &n, int a) : name(n), age(a) {}

    // Overload << operator for writing to file
    friend std::ostream &operator<<(std::ostream &os, const Person &p)
    {
        os << p.name << " " << p.age;
        return os;
    }

    // Overload >> operator for reading from file
    friend std::istream &operator>>(std::istream &is, Person &p)
    {
        is >> p.name >> p.age;
        return is;
    }
};
void writePeopleToFile(const std::string &filename)
{
    try
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Unable to open file for writing");
        }
        Person p1("Alice", 30);
        Person p2("Bob", 25);
        file << p1 << std::endl;
        file << p2 << std::endl;
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error writing to file: " << e.what() << std::endl;
    }
}

void readPeopleFromFile(const std::string &filename)
{
    try
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            throw std::runtime_error("Unable to open file for reading");
        }
        Person readPerson;
        while (file >> readPerson)
        {
            std::cout << "Read: " << readPerson.name << ", " << readPerson.age << std::endl;
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error reading from file: " << e.what() << std::endl;
    }
}

int main()
{
    std::string filename = "people.txt";
    writePeopleToFile(filename);
    readPeopleFromFile(filename);
    return 0;
}
