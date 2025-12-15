// ex00/main.cpp
#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

static int printUsage(const char *prog)
{
    std::cerr << "Usage: " << prog << " <literal>\n"
              << "Example literals:\n"
              << "  'a'    (char)\n"
              << "  42     (int)\n"
              << "  42.0f  (float)\n"
              << "  42.0   (double)\n"
              << "Pseudo-literals:\n"
              << "  nan, +inf, -inf, nanf, +inff, -inff\n";
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return printUsage(argv[0]);

    // Required by the subject: test the ScalarConverter with a single input literal.
    // Output formatting/conversion logic must stay inside ScalarConverter::convert().
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}
