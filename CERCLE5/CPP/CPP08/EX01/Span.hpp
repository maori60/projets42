#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>

class Span
{
public:
    Span();
    Span(unsigned int N);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void    addNumber(int n);
    void    addNumber(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end);

    int     shortestSpan() const;
    int     longestSpan() const;

    class FullContainerException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

private:
    unsigned int        _N;
    std::vector<int>    _v;
};

#endif
