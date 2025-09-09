#include "Fixed.hpp"

Fixed::Fixed() {
    _value = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    this->_value = other._value;
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_value = other._value;
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return(_value);
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}