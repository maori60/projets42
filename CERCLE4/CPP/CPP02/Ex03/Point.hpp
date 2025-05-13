#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point(); // Default constructor
    Point(const float x, const float y); // Constructeur paramétré
    Point(const Point& other); // Copie
    Point& operator=(const Point& other); // Affectation
    ~Point(); // Destructeur

    Fixed getX() const;
    Fixed getY() const;
};

#endif
