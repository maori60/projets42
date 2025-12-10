#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Constructors / Destructor

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: AForm(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// execute

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

// Helper for Intern

AForm	*PresidentialPardonForm::create(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}
