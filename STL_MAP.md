
# std::map in C++

`std::map` is a container in the C++ Standard Template Library (STL) that stores key-value pairs in a sorted order. It is implemented as a self-balancing binary search tree, typically a red-black tree.

## Key Features:

1. Ordered: Elements are sorted by keys.
2. Unique keys: Each key can appear only once.
3. Associative: Values are accessed by their keys, not by index.

## Important Functions:

1. `insert()`: Adds a key-value pair to the map.
   
   map.insert(std::pair<KeyType, ValueType>(key, value));
   // or
   map[key] = value;
   

2. `find()`: Searches for an element with a specific key.
   
   auto it = map.find(key);
   if (it != map.end()) {
       // Key found
   }
   

3. `erase()`: Removes an element with a given key.
   
   map.erase(key);
   

4. `size()`: Returns the number of elements in the map.
   
   size_t count = map.size();
   

5. `empty()`: Checks if the map is empty.
   
   if (map.empty()) {
       // Map is empty
   }
   

6. `clear()`: Removes all elements from the map.
   
   map.clear();
   

7. `count()`: Returns the number of elements with a specific key (0 or 1 for std::map).
   
   size_t num = map.count(key);
   

8. `begin()` and `end()`: Return iterators to the first element and one past the last element, respectively.
   
   for (auto it = map.begin(); it != map.end(); ++it) {
       // Access key with it->first, value with it->second
   }
   

9. `lower_bound()` and `upper_bound()`: Return iterators to the first element not less than the given key and the first element greater than the given key, respectively.
   
   auto it_lower = map.lower_bound(key);
   auto it_upper = map.upper_bound(key);
   

Time Complexity:
- Insertion, deletion, and search operations: O(log n)
- Accessing by key using operator[]: O(log n)

std::map is useful when you need to maintain a sorted collection of key-value pairs with fast lookup, insertion, and deletion operations.
