#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    Bureaucrat bob("Bob", 75);
    Bureaucrat alice("Alice", 5);

    Form f1("Form 451", 80, 90);  // Bob can sign it
    Form f2("Form 999", 50, 60);  // Only Alice can sign it

    std::cout << f1 << "\n";
    std::cout << f2 << "\n";

    bob.signForm(f1);  // Success
    bob.signForm(f2);  // Fail: grade too low
    alice.signForm(f2); // Success

    std::cout << f1 << "\n";
    std::cout << f2 << "\n";

    return 0;
}
