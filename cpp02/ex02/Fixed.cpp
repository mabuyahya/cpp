#include "Fixed.hpp"

Fixed::Fixed() {
    _value = 0;
}
Fixed::Fixed(const Fixed& other) {
    this->_value = other._value;
}
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other._value;
    return (*this);
}
Fixed::~Fixed() {
}
int Fixed::getRawBits(void) const{
    return(_value);
}
void Fixed::setRawBits(int const raw) {
    _value = raw;
}
Fixed::Fixed(const int value) {
    _value = value * (1 << _bits);
}
Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _bits));
}
float Fixed::toFloat() const{
    return ((float)_value / (1 << _bits));
}
int Fixed::toInt() const{
    return ((int)floor((float)_value / (1 << _bits)));
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool    Fixed::operator<(const Fixed& other) const{
    return (this->_value < other._value);
}
bool    Fixed::operator>(const Fixed& other) const{
    return (this->_value > other._value);
}
bool    Fixed::operator<=(const Fixed& other) const{
    return (this->_value <= other._value);
}
bool    Fixed::operator>=(const Fixed& other) const{
    return (this->_value >= other._value);
}
bool    Fixed::operator!=(const Fixed& other) const{
    return (this->_value != other._value);
}
bool    Fixed::operator==(const Fixed& other) const{
    return (this->_value == other._value);
}
Fixed Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const{
    long long result = (long long)this->_value * other._value;
    Fixed fixed;
    fixed.setRawBits((int)(result >> _bits));
    return fixed;
}
Fixed Fixed::operator/(const Fixed& other) const{
    long long temp = (long long)this->_value << _bits;
    Fixed fixed;
    fixed.setRawBits((int)(temp / other._value));
    return fixed;
}
Fixed& Fixed::operator++(){
    this->_value++;
    return (*this);
}
Fixed& Fixed::operator--(){
    this->_value--;
    return (*this);
}
Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->_value++;
    return (temp);
}
Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->_value--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    return(a < b ? a : b);
}
const   Fixed& Fixed::min(const Fixed& a,const Fixed& b){
    return(a < b ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b){
    return(a > b ? a : b);
}
const   Fixed& Fixed::max(const Fixed& a,const Fixed& b){
    return(a > b ? a : b);
}