#include "Replacer.hpp"

Replacer::Replacer() {}

Replacer::~Replacer() {}

std::string Replacer::replaceAll(std::string content, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return content;

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(content, pos);
    return result;
}
