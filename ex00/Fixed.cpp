#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits( int const raw ) {
    value = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;    
}