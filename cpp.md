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
what is actually happening is that the derived class has all the data members of the base class and put it in the first part of the derived class memory layout so the derived class object can be used as a base class object.
```cpp
class Base {
    public:
        int baseVar;
        void baseFunction() {
        }
};
// struct int and Base::baseFunction(Base* this) {}
class Derived : public Base {
    public:
        int derivedVar;
        void derivedFunction() {
        }
};
// struct int basevar; int derivedVar; and Derived::derivedFunction(Derived* this) {}
```
here we created a base class named Base and a derived class named Derived that inherits from the Base class.
when we create an object from the Derived class the memory layout will be like this:
```| baseVar | derivedVar |
so the derived class object can be used as a base class object.
when you call the baseFunction on the derived class object the this pointer will point to the derived class object but the function will only access the base class part of the object.
```cpp
Derived obj;
obj.baseFunction(); // this pointer points to obj but the function only access the base class part
```
what is really happening is that the compiler translates this code to this:
```cpp
Base::baseFunction((Base*)&obj);
```
so the derived class gets all the data members and functions of the base class.

#### what about virtual inheritance? //class FragTrap : virtual public ClapTrap
virtual inheritance is a way to prevent multiple copies of the base class when using multiple inheritance. when a class is derived from multiple base classes that have a common base class, the common base class is only included once in the derived class.

### polymorphism
* first what does the virtual keyword do?
when you have a class with virtual functions the compiler creates a vtable for that class and in side this vtable it keeps track of all the virtual functions of the class and their addresses. when you create an object from that class the compiler adds a pointer to the vtable in the object memory layout(this pointer is called vptr). when you call a virtual function on the object the compiler uses the vptr to get the vtable and then uses the vtable to get the address of the function and then calls the function.
* what is the use of this virtual functions?
the use of virtual functions is to achieve polymorphism. polymorphism is the ability of a function to behave differently based on the object that it is called on.
in other words its makes the compiler call the correct function based on the object type at runtime instead the pointer type at compile time.
```cpp
class Base {
    public:
        virtual void show() {
            cout << "Base class show function called" << endl;
        }
};

class Derived : public Base {
    public:
        void show() {
            cout << "Derived class show function called" << endl;
        }
};

int main() {
    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;

    basePtr->show(); // Output: Derived class show function called
    return 0;
}
```
here we have a base class named Base with a virtual function show and a derived class named Derived that overrides the show function. in the main function we create a base class pointer basePtr and a derived class object derivedObj. we assign the address of the derivedObj to the basePtr and then call the show function on the basePtr. because the show function is virtual the compiler uses the vptr to get the vtable and then uses the vtable to get the address of the show function of the derived class and then calls the function. so the output is "Derived class show function called".

### abstract classes and pure virtual functions
an abstract class is a class that cannot be instantiated. an abstract class is created by declaring at least one pure virtual function in the class. a pure virtual function is a virtual function that has no implementation and is declared by assigning 0 to the function declaration.
and we use abstract classes to define interfaces for derived classes. so any class that derives from an abstract class must implement all the pure virtual functions of the abstract class.
and we use the abstract classes to achieve polymorphism.
```cpp
class AbstractClass {
    public:
        virtual void pureVirtualFunction() = 0; // Pure virtual function
};
class DerivedClass : public AbstractClass {
    public:
        void pureVirtualFunction() {
            cout << "Derived class implementation of pure virtual function" << endl;
        }
};
int main() {
    // AbstractClass obj; // Error: Cannot instantiate abstract class
    AbstractClass *obj;
    DerivedClass derivedObj;
    obj = &derivedObj;
    obj->pureVirtualFunction(); // Output: Derived class implementation of pure virtual function
    return 0;
}
```
here we have an abstract class named AbstractClass with a pure virtual function pureVirtualFunction. we use a derived class to implement the pure virtual function and then we can call the function using a base class pointer.

### exceptions in c++
exceptions are a way to handle errors and exceptional situations in a program. in c++ we use the try, catch, and throw keywords to handle exceptions.
* **try block**: the code that may throw an exception is placed inside a try block.
* **throw statement**: when an exception occurs, a throw statement is used to throw an exception object. the throw statement takes an object as an argument. when the compiler encounters a throw statement in a function, it immediately stops executing the function and calls all the destructors for the local objects in that function before transferring control to the nearest catch block that can handle the exception. and gives the chatch block the exception object that was thrown.
* **catch block**:
the catch block is used to handle the exception that was thrown. the catch block takes an exception object as an argument and contains the code that handles the exception.
```cpp
#include <iostream>
using namespace std;
int divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero error"; // Throwing an exception
    }
    return a / b;
}
int main() {
    try {
        int result = divide(10, 0); // This will throw an exception
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl; // Handling the exception
    }
    return 0;
}
```
here we have a function named divide that takes two integers as arguments and returns the result of dividing the first integer by the second integer. if the second integer is zero the function throws an exception. in the main function we call the divide function inside a try block and catch the exception in a catch block.

### casting in c++

in c++ there are the normal c style cast but the c style casting is just a one style that get used to do all the casting types but in c++ there are four different casting types that are used for different purposes and they are:
1. **static_cast**: the static cast in the normal casting that we used to do in c style casting. it is used for compile-time type conversions. it is used to convert between related types, such as convertions that happend between float and double and int and char.
2. **reinterpret_cast**: the reinterpret cast is used for low-level reinterpreting of bit patterns. it is used to convert between unrelated types, such as converting a pointer to an integer or vice versa. in the low level the pointer is just a memory address(bits) so we can convert it to an integer that represents that address. so the integer and the pointer both when they get sorted in bits they will be the same. but the difference is in how the compiler treats them.
4. **dynamic_cast**: the dynamic cast is used for safe downcasting of polymorphic types. it is used to convert a base class pointer to a derived class pointer. it performs a runtime check to ensure that the conversion is valid.
3. **const_cast**: used to add or remove the const qualifier from a variable. it is used to modify a variable that is declared as const.

### templates in c++
templates are a way to create generic classes and functions in c++. templates allow you to define a class or function that can work with any data type. there are two types of templates in c++: class templates and function templates.
* **class templates**: class templates are used to create generic classes. a class template is defined using the template keyword followed by the template parameters in angle brackets.
* **function templates**: function templates are used to create generic functions. a function template is defined using the template keyword followed by the template parameters in angle brackets.
what is really happening is that when you make a template fucntion there won't be any code stored in the binary file it is just a blueprint for the compiler to create the function when it is called with a specific data type.
```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Int addition: " << add(5, 10) << endl;
    cout << "Double addition: " << add(5.5, 10.5) << endl;
    return 0;
}
```
so here when we created the function template no code was created but when we called the function with int and double the compiler created two functions one for int and one for double.

### containers in c++
containers are data structures that are used to store and organize data in c++. the standard template library (STL) provides a variety of containers that can be used to store data.
what really the containers are is that they are class templates that are defined in the STL library and they provide a way to store and organize data in a specific way.
for example the vector container is just a class template that has an array inside it and provides functions to add, remove, and access elements in the array.
and also the class handles the memory management for the array if it get full and need to be resized it will handle that for you.

### algorithms in c++
algorithms are functions that operate on containers to perform various operations such as searching, sorting, and manipulating data. the STL provides a rich set of algorithms that can be used with any container that supports iterators.

### what is iterators and why do i need them?
iterators are objects that provide a way to access the elements of a container sequentially without exposing the underlying structure of the container. iterators are similar to pointers in c and c++ but they provide a higher level of abstraction.
you need iterators because they provide a way to access the elements of a container without knowing the underlying structure of the container. this allows you to write generic algorithms that can work with any container that supports iterators.
what the iterators really is that they are just class templates that provide functions to access the elements of a container. each container has its own iterator class that is defined in the STL library.
for example the vector container has a vector::iterator class that provides functions to access the elements of the vector.
so if i want to make a algorithm that works with vectors and trees at the same time i can just use iterators to access the elements of the containers without knowing the underlying structure of the containers. because the tree stores its elements in a different way than the vector but both containers provide iterators to access their elements so i didn't need to worry about who to move between the elements because the iterators will take care of that for me.
