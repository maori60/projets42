/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2025/12/13                               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

static void printSection(const std::string &title)
{
    std::cout << "\n========================================\n";
    std::cout << title << "\n";
    std::cout << "========================================\n";
}

static void printSpans(const Span &sp, const std::string &label)
{
    std::cout << label << "\n";
    try
    {
        std::cout << "  shortestSpan: " << sp.shortestSpan() << "\n";
        std::cout << "  longestSpan : " << sp.longestSpan() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "  ERROR (" << e.what() << ")\n";
    }
}

int main()
{
    std::srand(std::time(NULL));

    printSection("EX01 - Span (clear tests)");

    // 0) NOT ENOUGH NUMBERS (montre l'exception)
    {
        printSection("0) Not enough numbers tests");
        Span sp(2);

        printSpans(sp, "[Span] With 0 number(s):"); // doit throw

        sp.addNumber(42);
        printSpans(sp, "[Span] With 1 number(s):"); // doit throw
    }

    // 1) SUBJECT-LIKE SMALL TEST
    {
        printSection("1) Small span (subject-like)");
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        printSpans(sp, "[Span] After adding 5 numbers:");

        std::cout << "[Span] Try to add a 6th number -> ";
        try
        {
            sp.addNumber(999);
            std::cout << "OK (unexpected)\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "ERROR (" << e.what() << ")\n";
        }
    }

    // 2) RANGE INSERTION (100)
    {
        printSection("2) Range insertion (100 values)");
        Span sp(100);
        std::vector<int> v;
        v.reserve(100);

        for (int i = 0; i < 100; ++i)
            v.push_back(std::rand() % 1000000);

        std::cout << "[Span] addNumber(range 100) -> ";
        try
        {
            sp.addNumber(v.begin(), v.end());
            std::cout << "OK\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "ERROR (" << e.what() << ")\n";
        }

        printSpans(sp, "[Span] After range insertion:");
    }

    // 3) LARGE RANGE TEST (100000)
    {
        printSection("3) Large range (100000 values)");
        Span sp(100000);
        std::vector<int> v;
        v.reserve(100000);

        for (int i = 0; i < 100000; ++i)
            v.push_back(std::rand()); // rapide, int

        std::cout << "[Span] addNumber(range 100000) -> ";
        try
        {
            sp.addNumber(v.begin(), v.end());
            std::cout << "OK\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "ERROR (" << e.what() << ")\n";
        }

        printSpans(sp, "[Span] After large insertion:");
    }

    std::cout << "\n[Span] Done.\n";
    return 0;
}
