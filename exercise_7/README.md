
| Aspect | C for loop | C++ range-based for loop |
|--------|------------|--------------------------|
| Syntax | `for (int i = 0; i < n; i++) { ... }` | `for (auto element : container) { ... }` |
| Iteration | Manually controlled | Automatically iterates over elements |
| Index access | Explicit via loop variable | Not directly available (can use `std::distance`) |
| Flexibility | Can iterate in any order or step | Iterates sequentially over all elements |
| Container types | Works with arrays and pointer arithmetic | Works with any range (arrays, containers, etc.) |
| Performance | May be slightly faster in some cases | Generally optimized, often as fast as C-style loop |
| Readability | More verbose, prone to off-by-one errors | More concise and less error-prone |
| Modification | Can modify loop variable within the loop | Uses a copy by default, use reference for modification |
| C++ version | Not applicable (C feature) | Introduced in C++11 |
| Use with custom types | Requires explicit iteration logic | Works with any type that provides begin() and end() |
