#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(): value_(0) {
}

Fixed::Fixed(const Fixed& other): value_(other.value_) {
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        value_ = other.value_;
    }
    return *this;
}

Fixed::Fixed(const int nbr) {
    value_ = nbr << fractBits;
}

Fixed::Fixed(const float nbr) {
    value_ = roundf(nbr * (1 << fractBits));
}

int Fixed::getRawBits( void ) const {
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
}

//comparison operators
bool Fixed::operator<(const Fixed& other) const{
	return this->value_ < other.value_ ;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->value_ > other.value_;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->value_ <= other.value_;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->value_ >= other.value_ ;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->value_ == other.value_;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->value_ != other.value_;
}

//arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());;
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

//increment/decrement operators
Fixed& Fixed::operator++() {
	value_ += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--() {
	value_ += 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

//max/min
const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2) {
	return (n1 < n2 ? n1 : n2);
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2) {
	return (n1 > n2 ? n1 : n2);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2) {
	return (n1 < n2 ? n1 : n2);
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2) {
	return (n1 > n2 ? n1 : n2);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}