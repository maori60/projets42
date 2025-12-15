/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+ +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:30:36 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/13 00:30:00 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void	printHeader(const std::string &title)
{
	std::cout << "\n============================================================\n";
	std::cout << title << std::endl;
	std::cout << "============================================================\n";
}

static void	printRule(const std::string &rule, const std::string &expected)
{
	std::cout << "RULE     : " << rule << std::endl;
	std::cout << "EXPECTED : " << expected << std::endl;
	std::cout << "------------------------------------------------------------\n";
}

static void	printState(const Bureaucrat &b, const AForm &f)
{
	std::cout << "STATE -> " << b << std::endl;
	std::cout << "STATE -> " << f << std::endl;
}

static void	printStep(int n, const std::string &label)
{
	std::cout << "\n[" << n << "] " << label << std::endl;
}

int	main(void)
{
	/*
	** TEST 1
	** RULE: A bureaucrat with too low authority cannot sign the form.
	*/
	printHeader("TEST 1 - SIGNATURE REFUSED (grade too low)");
	printRule("Bureaucrat grade must be <= form sign grade",
			  "signForm fails and prints an explicit error");
	{
		Bureaucrat				low("Default", 150);
		PresidentialPardonForm	pardon("target_1");

		printState(low, pardon);

		printStep(1, "Try to sign PresidentialPardonForm with grade 150");
		low.signForm(pardon);

		std::cout << "\nFINAL STATE\n";
		std::cout << "STATE -> " << pardon << std::endl;
	}

	/*
	** TEST 2
	** RULES:
	** 1) A form cannot be executed if it is not signed.
	** 2) Signing requires a high enough grade.
	** 3) Execution requires a high enough grade.
	*/
	printHeader("TEST 2 - EXECUTION & SIGNATURE RULES (not signed / grade checks)");
	printRule("execute requires: form signed + executor grade <= exec grade",
			  "executeForm fails if not signed OR grade too low; succeeds otherwise");
	{
		Bureaucrat				assistant("Assistant", 145);
		Bureaucrat				ceo("CEO", 1);
		PresidentialPardonForm	pardon("target_2");

		printState(assistant, pardon);
		printState(ceo, pardon);

		printStep(1, "Try execute BEFORE signing (should fail: not signed)");
		ceo.executeForm(pardon);

		printStep(2, "Assistant tries to SIGN (should fail: grade too low for sign)");
		assistant.signForm(pardon);

		printStep(3, "CEO SIGNS (should succeed)");
		ceo.signForm(pardon);
		std::cout << "STATE -> " << pardon << std::endl;

		printStep(4, "Assistant tries to EXECUTE (should fail: grade too low for exec)");
		assistant.executeForm(pardon);

		printStep(5, "CEO EXECUTES (should succeed: action + executed message)");
		ceo.executeForm(pardon);

		std::cout << "\nFINAL STATE\n";
		std::cout << "STATE -> " << pardon << std::endl;
	}

	/*
	** TEST 3
	** RULE: Copy should behave like the original object (canonical behavior).
	*/
	printHeader("TEST 3 - COPY CONSTRUCTOR (canonical behavior)");
	printRule("Copy of a form remains usable and independent",
			  "both original and copy can be signed and executed");
	{
		Bureaucrat				emperor("Emperor", 1);
		PresidentialPardonForm	original("target_3");
		PresidentialPardonForm	copy(original);

		printState(emperor, original);
		printState(emperor, copy);

		printStep(1, "Sign BOTH forms");
		emperor.signForm(original);
		emperor.signForm(copy);

		printStep(2, "Execute BOTH forms");
		emperor.executeForm(original);
		emperor.executeForm(copy);
	}

	/*
	** TEST 4
	** RULES:
	** - Polymorphism: execute should call the right concrete action.
	** - Robotomy: 50% success / 50% failure (approx).
	** - Shrubbery: creates <target>_shrubbery file.
	*/
	printHeader("TEST 4 - POLYMORPHISM (Robotomy + Shrubbery)");
	printRule("executeForm triggers concrete action after checks",
			  "Robotomy prints drilling + success/fail; Shrubbery creates a file");
	{
		Bureaucrat				emperor("Emperor", 1);
		RobotomyRequestForm		robot("Bender");
		ShrubberyCreationForm	tree("christmas");

		printState(emperor, robot);
		printState(emperor, tree);

		printStep(1, "Sign BOTH forms");
		emperor.signForm(robot);
		emperor.signForm(tree);

		printStep(2, "Execute Robotomy 10 times (observe random success/failure)");
		for (int i = 1; i <= 10; i++)
		{
			std::cout << "\n--- Robotomy attempt " << i << " ---" << std::endl;
			emperor.executeForm(robot);
		}

		printStep(3, "Execute Shrubbery (should create 'christmas_shrubbery')");
		emperor.executeForm(tree);
	}

	return (0);
}
