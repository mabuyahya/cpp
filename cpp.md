### what is c++?
C++ is a high-level programming language that was developed as an extension of the C programming language. It was created by Bjarne Stroustrup in the early 1980s at Bell Labs. C++ is known for its performance, efficiency, and flexibility, making it a popular choice for system/software development, game development, and applications requiring high performance.

### features of c++
1. **Object-Oriented Programming (OOP)**: C++ supports OOP principles such as encapsulation, inheritance, and polymorphism, allowing for modular and reusable code.
2. **Standard Template Library (STL)**: C++ includes the STL, which provides a rich set of template classes and functions for data structures and algorithms, promoting code reuse and efficiency.
3. **Memory Management**: C++ allows for manual memory management through pointers and dynamic allocation, giving developers fine-grained control over system resources.
4. **Performance**: C++ is known for its high performance and low-level access to memory, making it suitable for resource-intensive applications.
5. **Compatibility with C**: C++ is compatible with C, allowing developers to use existing C code and libraries seamlessly.

### what is the difference between c and c++?
1. **Paradigm**: C is a procedural programming language, while C++ supports both procedural and object-oriented programming paradigms.
* C++ is a object-oriented programming language.
2. **Data Abstraction**: C++ provides features for data abstraction through classes and objects, whereas C relies on structures and functions.
* data abstraction is more in c++, in c we have structures and data types(int , float), but in c++ we have classes which i will take about later. 
3. **Standard Library**: C++ has a more extensive standard library, including the Standard Template Library (STL), while C has a more limited standard library.
* in c++ there a STL library which has many data structures and algorithms, that you can use to make coding easier.
4. **Function Overloading**: C++ supports function overloading, allowing multiple functions with the same name but different parameters, while C does not.
* function overloading is only in c++.

### basic structure of a c++ program
```cpp
#include <iostream> // Preprocessor directive to include the iostream library
using namespace std; // Use the standard namespace

int main() {
    cout << "Hello, World!"; // Output "Hello, World!" to the console
    return 0; // Return 0 to indicate successful completion
}
```

# Now from now on we will explore most the c++ topics in depth and in the way that i understand them maybe the ranking of the topics won't be the best.

### compiling and running a c++ program

compiling and running a c++ program is the same as c program, but we will use the c++ compiler g++ instead of gcc. 
in c++ we use the header file (hpp) instead of (h) but both are same.
in c++ we use the header for the same purpose as in c(for including, prototyping) but in c++ we also uses the header files for our classes(for the same reason we was puting our struct in the header) for readability and organization.

#### basic input and output in c++
here became the first big difference between c and c++.
in c we use the printf(write(fd, buf, num)) and scanf(read()) functions for input and output.
but in c++ we there are a better and easier and different way for that and to understand that we need to understand two things:
1. **what is cout**: cout is just an object from the ostream class in this class there a variables(the fd for the standard output) and functions
2. **what is cin**: cin is just an object from the istream class in this class there a variables(the fd for the standard input) and functions
3. **what is << and >>?**: << is the stream insertion operator and >> is the stream extraction operator