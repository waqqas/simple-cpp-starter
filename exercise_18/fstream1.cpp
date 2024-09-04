#include <iostream>
#include <fstream>
#include <string>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    try
    {
        std::ifstream input_file(argv[1]);
        if (!input_file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + std::string(argv[1]));
        }

        std::string line;
        while (std::getline(input_file, line))
        {
            // Process each line
            std::cout << line << std::endl;
        }
        input_file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
