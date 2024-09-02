
# Functor in C++

A functor, also known as a function object, is a class or struct that overloads the function call operator `operator()`. This allows objects of the class to be used as if they were functions.

## Key characteristics of functors:

1. They are objects that can be called as if they were functions.
2. They can maintain state between function calls.
3. They can be passed as arguments to algorithms or other functions.

## Example of a simple functor:

```
class Multiplier {
private:
    int factor;

public:
    Multiplier(int f) : factor(f) {}

    int operator()(int x) const {
        return x * factor;
    }
};

// Usage
Multiplier times3(3);
int result = times3(5); // result is 15
```

## Uses of functors in C++:

1. **Customizing standard algorithms**: Functors can be used to provide custom behavior to standard algorithms.

```   
   std::vector<int> numbers = {1, 2, 3, 4, 5};
   std::transform(numbers.begin(), numbers.end(), numbers.begin(), Multiplier(2));
   // numbers is now {2, 4, 6, 8, 10}
```   

2. **Maintaining state**: Functors can store data and maintain state between calls.

```
   class Counter {
   private:
       int count = 0;
   public:
       int operator()() {
           return ++count;
       }
   };

   Counter c;
   std::cout << c() << std::endl; // Outputs: 1
   std::cout << c() << std::endl; // Outputs: 2
```   

3. **Callback mechanisms**: Functors can be used as callbacks in event-driven programming.

```
   class ButtonClickHandler {
   public:
       void operator()(const std::string& buttonName) {
           std::cout << "Button " << buttonName << " was clicked!" << std::endl;
       }
   };

   // Usage
   ButtonClickHandler clickHandler;
   button.setOnClickListener(clickHandler);
   // When the button is clicked, it will call clickHandler("ButtonName")
```
4. **Policy-based design**: Functors can be used to implement policies in template-based designs.

```
   template<typename SortPolicy>
   class Sorter {
   public:
       void sort(std::vector<int>& data) {
           SortPolicy()(data);
       }
   };

   struct BubbleSortPolicy {
       void operator()(std::vector<int>& data) {
           // Bubble sort implementation
           for (size_t i = 0; i < data.size() - 1; ++i) {
               for (size_t j = 0; j < data.size() - i - 1; ++j) {
                   if (data[j] > data[j + 1]) {
                       std::swap(data[j], data[j + 1]);
                   }
               }
           }
       }
   };

   struct QuickSortPolicy {
       void operator()(std::vector<int>& data) {
           // Quick sort implementation (simplified)
           std::sort(data.begin(), data.end());
       }
   };

   // Usage
   std::vector<int> numbers = {5, 2, 8, 1, 9};
   Sorter<BubbleSortPolicy> bubbleSorter;
   bubbleSorter.sort(numbers);

   numbers = {5, 2, 8, 1, 9};
   Sorter<QuickSortPolicy> quickSorter;
   quickSorter.sort(numbers);
```

5. **Lambda expressions**: In modern C++, lambda expressions provide a concise way to create functors inline.

```   
   auto multiplier = [factor = 3](int x) { return x * factor; };
   std::cout << multiplier(5) << std::endl; // Outputs: 15
```   

Functors provide a powerful and flexible way to customize behavior in C++ programs, especially when working with generic algorithms and containers.
