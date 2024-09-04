#include <exception>
#include <string>

class CustomException : public std::exception
{
private:
    std::string message;

public:
    explicit CustomException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

void riskyFunction(int value)
{
    if (value < 0)
    {
        throw CustomException("Negative value not allowed");
    }
    // Rest of the function...
}

#include <iostream>

int main()
{
    try
    {
        riskyFunction(-5);
    }
    catch (const CustomException &e)
    {
        std::cerr << "Caught custom exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught standard exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Caught unknown exception" << std::endl;
    }

    return 0;
}