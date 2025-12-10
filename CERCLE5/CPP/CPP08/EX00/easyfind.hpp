#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

class NotFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Value not found in container";
    }
};

template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
    typename T::const_iterator it =
        std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw NotFoundException();

    return it;
}

#endif
