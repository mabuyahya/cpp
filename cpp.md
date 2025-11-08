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
1. **what is cout**: cout is just an object from the ostream class in this class there a variables(the fd for the standard output) and functions that do things like writing to that fd also there are a layer for changing the input to a sequence of characters so it can be printed..
2. **what is cin**: cin is just an object from the istream class in this class there a variables(the fd for the standard input) and functions that do things like reading from that fd also there are a layer for changing the sequence of characters to the input type so it can be stored in that type.
3. **what is << and >>?**: the operator<<>> is a function that exists in c++ and when i do this cout << "Hello"; it is the same as calling the function operator<<(cout, "Hello"); so this function takes the object(cout) and the value("Hello") and does the output operation.

### while, for loop, if statements are the same as c language

### functions in c++ are same as c language but with some differences
* **Function Overloading**: C++ allows multiple functions to have the same name with different parameter lists, enabling function overloading. This feature is not available in C.

### Classes 
Classes are just a blueprint for creating objects. when you create a class you are just defining a new data type just like structs in c also creating functions but that functions will be appended with the class name also these functions will have a invisible argument that will point to the object that called the function(this pointer).
so when you create an object from a class you are creating a variable from that data type just like in c when you create a struct variable.
but what is special about these data types is that not all the functions can access all the data members of the class, you can define the access level of each data member using the keywords public, private, and protected.

```cpp
class MyClass {
    public: 
        int myVar;
        int myVarSecond;

    public:
        void myFunction() {
        }
};
```
in this example we created a class named MyClass that has a public data member myVar and a public function myFunction.
the complier sees this code like this:
```cpp
struct MyClass {
    int myVar;
    int myVarsecond;
};
void MyClass::myFunction(class MyClass* this) {
}
```
### Objects

MyClass obj;

here we created an object named obj from the class MyClass. in the memory there will be allocated space for the data members of the class. in the memory there will be space for two integers(myVar and myVarSecond) and this space is called obj.

obj.myFunction();

this line of code is translated by the compiler to this:
MyClass::myFunction(&obj);
the myFunction function is called with the address of the object obj as the invisible argument this.

### constructors and destructors
constructors are special functions that are called when an object is created. the name of the constructor is the same as the class name and it has no return type.
destructors are special functions that are called when an object is destroyed. the name of the destructor is the same as the class name with a ~ before it and it has no return type.

### inheritance
inheritance is a way to create a new class from an existing class. the new class is called the derived class and the existing class is called the base class. the derived class inherits the data members and functions of the base class.
what is actually happening is that the derived class has all the data members and functions of the base class and you can