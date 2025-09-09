#include "Fixed.hpp"
#include <iostream>
#include <iomanip> // For std::boolalpha

int main( void ) {

    std::cout << "--- CONSTRUCTORS & BASIC OUTPUT ---" << std::endl;
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << std::endl;

    std::cout << "--- COMPARISON OPERATORS ---" << std::endl;
    Fixed e(10);
    Fixed f(20);
    std::cout << std::boolalpha; // Print true/false instead of 1/0
    std::cout << "e is " << e << ", f is " << f << std::endl;
    std::cout << "e > f : " << (e > f) << std::endl;   // false
    std::cout << "e < f : " << (e < f) << std::endl;   // true
    std::cout << "e >= f: " << (e >= f) << std::endl;  // false
    std::cout << "e <= f: " << (e <= f) << std::endl;  // true
    std::cout << "e == f: " << (e == f) << std::endl;  // false
    std::cout << "e != f: " << (e != f) << std::endl;  // true
    std::cout << "e == Fixed(10): " << (e == Fixed(10)) << std::endl; // true
    std::cout << std::endl;


    std::cout << "--- ARITHMETIC OPERATORS ---" << std::endl;
    Fixed g(5.05f);
    Fixed h(2);
    std::cout << "g is " << g << ", h is " << h << std::endl;
    std::cout << "g + h = " << g + h << " (Expected ~7.05)" << std::endl;
    std::cout << "g - h = " << g - h << " (Expected ~3.05)" << std::endl;
    std::cout << "g * h = " << g * h << " (Expected ~10.1)" << std::endl;
    std::cout << "g / h = " << g / h << " (Expected ~2.52)" << std::endl;
    std::cout << std::endl;

    std::cout << "--- INCREMENT/DECREMENT OPERATORS ---" << std::endl;
    Fixed i;
    std::cout << "Initial i: " << i << std::endl;
    std::cout << "++i      : " << ++i << std::endl;
    std::cout << "i after ++i: " << i << std::endl;
    std::cout << "i++      : " << i++ << " (should be the value before increment)" << std::endl;
    std::cout << "i after i++: " << i << std::endl;
    std::cout << std::endl;

    Fixed j;
    std::cout << "Initial j: " << j << std::endl;
    std::cout << "--j      : " << --j << std::endl;
    std::cout << "j after --j: " << j << std::endl;
    std::cout << "j--      : " << j-- << " (should be the value before decrement)" << std::endl;
    std::cout << "j after j--: " << j << std::endl;
    std::cout << std::endl;


    std::cout << "--- MIN/MAX FUNCTIONS ---" << std::endl;
    // Test non-const version
    Fixed x(100.5f);
    Fixed y(200.5f);
    std::cout << "x is " << x << ", y is " << y << std::endl;
    std::cout << "Fixed::min(x, y) = " << Fixed::min( x, y ) << std::endl;
    std::cout << "Fixed::max(x, y) = " << Fixed::max( x, y ) << std::endl;
    std::cout << std::endl;

    // Test const version
    const Fixed cx(100.5f);
    const Fixed cy(200.5f);
    std::cout << "cx is " << cx << ", cy is " << cy << " (const objects)" << std::endl;
    std::cout << "Fixed::min(cx, cy) = " << Fixed::min( cx, cy ) << std::endl;
    std::cout << "Fixed::max(cx, cy) = " << Fixed::max( cx, cy ) << std::endl;
    std::cout << std::endl;


    std::cout << "--- SUBJECT MAIN ---" << std::endl;
    Fixed subj_a;
    Fixed const subj_b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << subj_a << std::endl;
    std::cout << ++subj_a << std::endl;
    std::cout << subj_a << std::endl;
    std::cout << subj_a++ << std::endl;
    std::cout << subj_a << std::endl;
    std::cout << subj_b << std::endl;
    std::cout << Fixed::max( subj_a, subj_b ) << std::endl;
    std::cout << std::endl;

    std::cout << "--- DESTRUCTORS ---" << std::endl;
    return 0;
}