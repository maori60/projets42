#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
public:
    Replacer();
    ~Replacer();
    static std::string replaceAll(std::string content, const std::string& s1, const std::string& s2);
};

#endif
