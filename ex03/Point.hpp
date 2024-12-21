#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"


class Point {
public:
    Point(const float x, const float y);
    ~Point();
private:
    Fixed const x;
    Fixed const y;
};

#endif