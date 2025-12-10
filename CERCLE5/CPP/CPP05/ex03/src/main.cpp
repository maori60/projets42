#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Intern		someRandomIntern;
	AForm		*form;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	peon("Peon", 150);

	std::cout << "=== Intern creates a shrubbery form ===" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form != 0)
	{
		std::cout << *form << std::endl;
		peon.signForm(*form);   // should fail
		boss.signForm(*form);   // should succeed
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl << "=== Intern creates a robotomy request ===" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form != 0)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl << "=== Intern creates a presidential pardon ===" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form != 0)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << std::endl << "=== Intern tries an unknown form ===" << std::endl;
	form = someRandomIntern.makeForm("coffee making", "nobody");
	if (form != 0)
		delete form;

	return (0);
}
