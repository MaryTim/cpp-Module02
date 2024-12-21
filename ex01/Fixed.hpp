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
private:
    int value_;
    static const int fractBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
