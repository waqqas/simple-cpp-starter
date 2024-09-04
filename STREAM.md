
# STL Stream Operators and File I/O with fstream

## Stream Operators in C++

In C++, stream operators (`<<` for output and `>>` for input) are used to perform input/output operations. These operators are overloaded to work with various data types and objects.

- `<<` (insertion operator): Used for output, e.g., `cout << "Hello, World!";`
- `>>` (extraction operator): Used for input, e.g., `cin >> variable;`

## Using fstream for File I/O

The `<fstream>` library provides classes for file input/output operations:

1. `ifstream`: Input file stream (reading from files)
2. `ofstream`: Output file stream (writing to files)
3. `fstream`: General file stream (both reading and writing)

### Reading from a File


#include <fstream>
#include <string>

std::ifstream input_file("example.txt");
std::string line;

if (input_file.is_open()) {
    while (std::getline(input_file, line)) {
        // Process each line
        std::cout << line << std::endl;
    }
    input_file.close();
}


### Writing to a File


#include <fstream>

std::ofstream output_file("example.txt");

if (output_file.is_open()) {
    output_file << "Hello, World!" << std::endl;
    output_file << "This is a new line." << std::endl;
    output_file.close();
}


### Reading and Writing with fstream


#include <fstream>
#include <string>

std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);

if (file.is_open()) {
    // Writing to the file
    file << "Appending new content." << std::endl;

    // Reading from the file
    file.seekg(0, std::ios::beg);  // Move to the beginning of the file
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}


Remember to include error handling and close the file streams when you're done using them.


### Reading and Writing Custom Class with fstream

#include <fstream>
#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person() : name(""), age(0) {}
    Person(const std::string& n, int a) : name(n), age(a) {}

    // Overload << operator for writing to file
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << p.name << " " << p.age;
        return os;
    }

    // Overload >> operator for reading from file
    friend std::istream& operator>>(std::istream& is, Person& p) {
        is >> p.name >> p.age;
        return is;
    }
};

int main() {
    std::fstream file("people.txt", std::ios::in | std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        // Writing custom objects to the file
        Person p1("Alice", 30);
        Person p2("Bob", 25);
        file << p1 << std::endl;
        file << p2 << std::endl;

        // Move to the beginning of the file for reading
        file.seekg(0, std::ios::beg);

        // Reading custom objects from the file
        Person readPerson;
        while (file >> readPerson) {
            std::cout << "Read: " << readPerson.name << ", " << readPerson.age << std::endl;
        }

        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return 0;
}
