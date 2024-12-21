#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(): value_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): value_(other.value_) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value_ = other.value_;
    }
    return *this;
}

Fixed::Fixed(const int nbr) {
    std::cout << "Int constructor called" << std::endl;
    value_ = nbr << fractBits;
}

Fixed::Fixed(const float nbr) {
    std::cout << "Float constructor called" << std::endl;
    value_ = roundf(nbr * (1 << fractBits));
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value_;
}

void Fixed::setRawBits( int const raw ) {
    value_ = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(value_) / (1 << fractBits);
}

int Fixed::toInt( void ) const {
    return value_ >> fractBits;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}