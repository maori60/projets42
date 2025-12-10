/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:31:16 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 18:54:22 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "\033[33m" << "Test small span\n" << "\033[0m";
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try
    {
        sp.addNumber(11);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[33m" << "Test vector range\n" << "\033[0m";
    Span sp2 = Span(100);
    std::vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        int random_int = std::rand() % 1000000;
        v.push_back(random_int);
    }
    try
    {
        sp2.addNumber(v.begin(), v.end());
        std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[33m" << "Test vector large range\n" << "\033[0m";
    Span sp3 = Span(100000);
    std::vector<int> v2;
    for (int i = 0; i < 100000; i++)
    {
        int random_int = std::rand() % 1000000000;
        v2.push_back(random_int);
    }
    try
    {
        sp3.addNumber(v2.begin(), v2.end());
        std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
