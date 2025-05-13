#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();                                // Constructeur par défaut
    Fixed(const int value);                 // Constructeur depuis int
    Fixed(const float value);               // Constructeur depuis float
    Fixed(const Fixed& other);              // Constructeur de copie
    Fixed& operator=(const Fixed& other);   // Opérateur d’affectation
    ~Fixed();                               // Destructeur

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif
