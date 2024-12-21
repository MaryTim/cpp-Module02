#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& other); //copy constructor
    Fixed& operator=(const Fixed& other); //copy assignment operator
    Fixed(const int nbr);
    Fixed(const float nbr);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    //overload comparison operators
    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    //overload arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    //overload increment/decrement operators
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    //overload max/min
    static const Fixed& min(const Fixed& n1, const Fixed& n2);
    static Fixed& min(Fixed& n1, Fixed& n2);
    static const Fixed& max(const Fixed& n1, const Fixed& n2);
    static Fixed& max(Fixed& n1, Fixed& n2);
private:
    int value_;
    static const int fractBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
