#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	Bureaucrat::_checkGrade(int grade) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	_checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		// _name est const -> non assignable
		_grade = src._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

const std::string	&Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade(void)
{
	_checkGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	_checkGrade(_grade + 1);
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat grade too low";
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return o;
}
