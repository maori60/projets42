/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/03 12:21:18 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void testSigning(const std::string &bName, int bGrade,
                        const std::string &fName, int signGrade, int execGrade)
{
    try
    {
        Bureaucrat bureaucrat(bName, bGrade);
        Form       form(fName, signGrade, execGrade);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception while creating/using objects: "
                  << e.what() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

int main(void)
{
    std::cout << "=== Valid signing ===" << std::endl;
    testSigning("Alice", 10, "TopSecret", 20, 5);

    std::cout << "=== Too low grade to sign ===" << std::endl;
    testSigning("Bob", 150, "ImportantPaper", 100, 50);

    std::cout << "=== Invalid form grades (too high) ===" << std::endl;
    try
    {
        Form invalid("BadFormHigh", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Invalid form grades (too low) ===" << std::endl;
    try
    {
        Form invalid("BadFormLow", 151, 10);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
