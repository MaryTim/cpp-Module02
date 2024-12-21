#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& other); //copy constructor
    Fixed& operator=(const Fixed& other); //copy assignment operator
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
private:
    int value;
    static const int fractBits;
};

#endif
