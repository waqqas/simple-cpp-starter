
# RAII (Resource Acquisition Is Initialization)

RAII is a programming idiom used in C++ and other languages that supports deterministic object lifetime. The main principles of RAII are:

1. Resource acquisition (allocation) is done during object initialization, usually in a constructor.
2. Resource release (deallocation) is done during object destruction, usually in a destructor.

Key benefits of RAII:

- Ensures proper management of resources like memory, file handles, network connections, etc.
- Helps prevent resource leaks by tying resource lifetime to object lifetime.
- Makes code exception-safe by automatically releasing resources when an exception occurs.
- Simplifies code by reducing the need for explicit resource management.

Example in C++:


class FileHandler {
private:
    FILE* file;

public:
    FileHandler(const char* filename) {
        file = fopen(filename, "r");
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandler() {
        if (file) {
            fclose(file);
        }
    }

    // Other member functions to work with the file
};


In this example, the file is opened in the constructor and automatically closed in the destructor, ensuring proper resource management regardless of how the object is used or destroyed.


| Feature | std::unique_ptr | std::shared_ptr | std::weak_ptr |
|---------|-----------------|-----------------|---------------|
| Ownership | Exclusive ownership | Shared ownership | Non-owning reference |
| Reference count | No | Yes | No |
| Can be copied | No | Yes | Yes |
| Can be moved | Yes | Yes | Yes |
| Automatically deletes | Yes, when unique_ptr is destroyed | Yes, when last shared_ptr is destroyed | No |
| Can be reset | Yes | Yes | Yes |
| Can be null | Yes | Yes | Yes |
| Supports custom deleters | Yes | Yes | No |
| Overhead | Minimal | Higher due to reference counting | Minimal |
| Use case | Single-object ownership | Shared ownership | Breaking circular references |
| Array support | Yes (C++17) | No (use vector<shared_ptr<T>> instead) | No |
| Thread-safe | Yes (for destruction) | Yes (for reference count) | No |
