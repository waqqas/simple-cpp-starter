
# Function Overloading in C++

Function overloading is a feature in C++ that allows multiple functions to have the same name but different parameters. This enables programmers to create functions that perform similar tasks but with different input types or number of arguments.

## Key Points:

1. **Same Name, Different Parameters**: Overloaded functions share the same name but have different parameter lists.

2. **Return Type**: The return type alone is not sufficient to differentiate overloaded functions.

3. **Resolution**: The compiler determines which function to call based on the number, types, and order of the arguments passed.

4. **Advantages**:
   - Improves code readability
   - Reduces complexity
   - Provides flexibility in function calls

5. **Example**:

   
   int add(int a, int b) {
       return a + b;
   }

   double add(double a, double b) {
       return a + b;
   }

   int add(int a, int b, int c) {
       return a + b + c;
   }
   

6. **Limitations**: 
   - Cannot overload functions that differ only by return type
   - Care must be taken to avoid ambiguity in function calls

Function overloading is a powerful feature that enhances the expressiveness and flexibility of C++ programming.
