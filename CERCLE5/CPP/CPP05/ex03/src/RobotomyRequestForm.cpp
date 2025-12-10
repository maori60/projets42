#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <ctime>

// Constructors / Destructor

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// execute

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);

	std::cout << "* Drilling noises *" << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << _target << " has failed..." << std::endl;
}

// Helper for Intern

AForm	*RobotomyRequestForm::create(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}
