#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed(const int value);
        Fixed(const float value);
        int getRawBits( void ) const;
        void setRawBits(int raw);
        float toFloat() const;
        int toInt() const;
        Fixed& operator=(const Fixed& other);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif