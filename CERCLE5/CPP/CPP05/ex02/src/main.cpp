/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:30:36 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:49:13 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// Test 1 : bureaucrate trop low pour signer
	std::cout << "================== TEST 1 ==================" << std::endl;
	{
		Bureaucrat *a = new Bureaucrat(); // grade 150
		AForm *b = new PresidentialPardonForm("default");

		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch (std::exception &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName()
				<< ": " << e.what() << std::endl;
		}

		std::cout << b;

		delete a;
		delete b;
	}

	// Test 2 : exécution avant signature, puis signature/exec avec bons grades
	std::cout << "\n================== TEST 2 ==================" << std::endl;
	{
		Bureaucrat *assistant = new Bureaucrat("Assistant", 145);
		Bureaucrat *ceo = new Bureaucrat("CEO", 1);
		AForm *form = new PresidentialPardonForm("some dude");

		std::cout << assistant;
		std::cout << ceo;
		std::cout << form;

		// Try to execute before signing
		try
		{
			form->execute(*ceo);
		}
		catch (std::exception &e)
		{
			std::cerr << assistant->getName() << " was not able to execute the Form "
				<< form->getName() << ": " << e.what() << std::endl;
		}

		// Assistant essaye de signer (trop low)
		try
		{
			form->beSigned(*assistant);
		}
		catch (std::exception &e)
		{
			std::cerr << assistant->getName() << " was not able to sign the Form "
				<< form->getName() << ": " << e.what() << std::endl;
		}

		// CEO signe
		std::cout << std::endl << form << std::endl;
		try
		{
			form->beSigned(*ceo);
		}
		catch (std::exception &e)
		{
			std::cerr << ceo->getName() << " was not able to sign the Form "
				<< form->getName() << ": " << e.what() << std::endl;
		}
		std::cout << form << std::endl;

		// execute depuis assistant (trop low)
		try
		{
			form->execute(*assistant);
		}
		catch (std::exception &e)
		{
			std::cerr << assistant->getName() << " was not able to execute the Form "
				<< form->getName() << ": " << e.what() << std::endl;
		}

		// execute depuis CEO
		try
		{
			form->execute(*ceo);
		}
		catch (std::exception &e)
		{
			std::cerr << ceo->getName() << " was not able to execute the Form "
				<< form->getName() << ": " << e.what() << std::endl;
		}

		delete assistant;
		delete ceo;
		delete form;
	}

	// Test 3 : PresidentialPardon + executeForm du Bureaucrat
	std::cout << "\n================== TEST 3 ==================" << std::endl;
	{
		Bureaucrat *emperor = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);

		std::cout << emperor;
		std::cout << b;
		std::cout << c;

		emperor->signForm(*b);
		emperor->signForm(*c);

		emperor->executeForm(*b);
		emperor->executeForm(*c);

		delete emperor;
		delete b;
		delete c;
	}

	// Test 4 : Robotomy + Shrubbery
	std::cout << "\n================== TEST 4 ==================" << std::endl;
	{
		Bureaucrat *emperor = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *robot = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *tree = new ShrubberyCreationForm("christmas");

		std::cout << emperor;
		std::cout << robot;
		std::cout << tree;

		emperor->signForm(*robot);
		emperor->signForm(*tree);

		for (int i = 0; i < 10; i++)
			emperor->executeForm(*robot);

		emperor->executeForm(*tree);

		delete emperor;
		delete robot;
		delete tree;
	}

	return (0);
}
