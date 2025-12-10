#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _v = other._v;
    }
    return (*this);
}

Span::~Span()
{
}

void    Span::addNumber(int n)
{
    if (_v.size() >= _N)
        throw FullContainerException();
    _v.push_back(n);
}

void    Span::addNumber(std::vector<int>::iterator begin,
                        std::vector<int>::iterator end)
{
    if (_v.size() + std::distance(begin, end) > _N)
        throw FullContainerException();
    _v.insert(_v.end(), begin, end);
}

int     Span::shortestSpan() const
{
    if (_v.size() <= 1)
        throw NotEnoughNumbersException();

    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());

    int min = tmp[1] - tmp[0];
    for (std::size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < min)
            min = diff;
    }
    return (min);
}

int     Span::longestSpan() const
{
    if (_v.size() <= 1)
        throw NotEnoughNumbersException();

    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::FullContainerException::what() const throw()
{
    return ("Container is full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("Not enough numbers in container");
}
