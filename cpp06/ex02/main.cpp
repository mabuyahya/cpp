#include "main_helper.hpp"

// class D : public Base{
// };

int main(void){
    Base *ptr;
    ptr = generate();
    identify(ptr);
    identify(*ptr);
        // D *d = new D();
        // identify(*d);
        // identify(d);
        // delete d;
    delete ptr;
}