// ex00/ScalarConverter.cpp
#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>      // strtod, strtol
#include <climits>      // INT_MIN, INT_MAX, CHAR_MIN, CHAR_MAX
#include <cfloat>       // DBL_MAX, etc.
#include <iomanip>      // fixed, setprecision
#include <limits>       // std::numeric_limits
#include <cmath>        // std::isnan, std::isinf
#include <cctype>       // std::isdigit, std::isprint

namespace
{
    enum LiteralType
    {
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_PSEUDO_FLOAT,
        TYPE_PSEUDO_DOUBLE,
        TYPE_INVALID
    };

    bool isPseudoFloat(const std::string &s)
    {
        return (s == "nanf" || s == "+inff" || s == "-inff");
    }

    bool isPseudoDouble(const std::string &s)
    {
        return (s == "nan" || s == "+inf" || s == "-inf");
    }

    LiteralType detectType(const std::string &s)
    {
        if (isPseudoFloat(s))
            return TYPE_PSEUDO_FLOAT;
        if (isPseudoDouble(s))
            return TYPE_PSEUDO_DOUBLE;

        if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
            return TYPE_CHAR;

        bool hasDot = false;
        bool hasF = false;
        std::size_t i = 0;

        if (s[i] == '+' || s[i] == '-')
            ++i;

        for (; i < s.length(); ++i)
        {
            char c = s[i];
            if (c == '.')
            {
                if (hasDot)
                    return TYPE_INVALID;
                hasDot = true;
            }
            else if (c == 'f' && i == s.length() - 1)
            {
                hasF = true;
            }
            else if (!std::isdigit(static_cast<unsigned char>(c)))
            {
                return TYPE_INVALID;
            }
        }

        if (hasDot && hasF)
            return TYPE_FLOAT;
        if (hasDot)
            return TYPE_DOUBLE;
        if (hasF)
            return TYPE_INVALID;
        return TYPE_INT;
    }

    void printPseudoFloat(const std::string &s)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << s << std::endl;

        if (s == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (s == "+inff")
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }

    void printPseudoDouble(const std::string &s)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << s << "f" << std::endl;
        std::cout << "double: " << s << std::endl;
    }

    void printFromDouble(double d)
    {
        // CHAR
        std::cout << "char: ";
        if (std::isnan(d) ||
            d < static_cast<double>(CHAR_MIN) ||
            d > static_cast<double>(CHAR_MAX))
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            char c = static_cast<char>(d); // static_cast pour cet exo
            if (std::isprint(static_cast<unsigned char>(c)))
                std::cout << "'" << c << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
        }

        // INT
        std::cout << "int: ";
        if (std::isnan(d) ||
            d < static_cast<double>(INT_MIN) ||
            d > static_cast<double>(INT_MAX))
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            int i = static_cast<int>(d); // static_cast
            std::cout << i << std::endl;
        }

        // FLOAT
        float f = static_cast<float>(d); // static_cast
        std::cout << "float: ";
        if (std::isnan(d))
        {
            std::cout << "nanf" << std::endl;
        }
        else if (std::isinf(d))
        {
            if (d > 0)
                std::cout << "+inff" << std::endl;
            else
                std::cout << "-inff" << std::endl;
        }
        else
        {
            std::cout.setf(std::ios::fixed);
            std::cout << std::setprecision(1) << f << "f" << std::endl;
        }

        // DOUBLE
        std::cout << "double: ";
        if (std::isnan(d))
        {
            std::cout << "nan" << std::endl;
        }
        else if (std::isinf(d))
        {
            if (d > 0)
                std::cout << "+inf" << std::endl;
            else
                std::cout << "-inf" << std::endl;
        }
        else
        {
            std::cout.setf(std::ios::fixed);
            std::cout << std::setprecision(1) << d << std::endl;
        }
    }
} // namespace

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);

    if (type == TYPE_INVALID)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (type == TYPE_PSEUDO_FLOAT)
    {
        printPseudoFloat(literal);
        return;
    }
    if (type == TYPE_PSEUDO_DOUBLE)
    {
        printPseudoDouble(literal);
        return;
    }

    double d = 0.0;

    if (type == TYPE_CHAR)
    {
        d = static_cast<double>(literal[0]); // point central : double
    }
    else if (type == TYPE_INT)
    {
        char *endptr = 0;
        long val = std::strtol(literal.c_str(), &endptr, 10);
        d = static_cast<double>(val);
    }
    else if (type == TYPE_FLOAT)
    {
        std::string tmp = literal.substr(0, literal.length() - 1);
        char *endptr = 0;
        double val = std::strtod(tmp.c_str(), &endptr);
        d = static_cast<double>(val);
    }
    else if (type == TYPE_DOUBLE)
    {
        char *endptr = 0;
        double val = std::strtod(literal.c_str(), &endptr);
        d = val;
    }

    printFromDouble(d);
}
