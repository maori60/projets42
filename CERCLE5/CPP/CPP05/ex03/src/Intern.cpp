#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern const &other) { (void)other; }
Intern::~Intern() {}
Intern	&Intern::operator=(Intern const &other) { (void)other; return (*this); }

AForm	*Intern::createShrubbery(std::string const &target)
{
	return (ShrubberyCreationForm::create(target));
}

AForm	*Intern::createRobotomy(std::string const &target)
{
	return (RobotomyRequestForm::create(target));
}

AForm	*Intern::createPresidential(std::string const &target)
{
	return (PresidentialPardonForm::create(target));
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &target)
{
	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	const t_creator		creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
			return (creators[i](target));
	}
	return (0);
}
