#include "Bureaucrat.hpp"

// ----- Private helper ------------------------------------------------------

void Bureaucrat::_checkGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// ----- Canonical form ------------------------------------------------------

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	// nothing
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	_checkGrade(grade);
}

Bureaucrat::Bureaucrat(int grade)
	: _name("Default"), _grade(grade)
{
	_checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade)
{
	// nothing else
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// _name is const → on ne le recopie pas
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	// nothing to free
}

// ----- Getters -------------------------------------------------------------

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// ----- Grade manipulation --------------------------------------------------

void Bureaucrat::incrementGrade()
{
	_checkGrade(_grade - 1);
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	_checkGrade(_grade + 1);
	_grade++;
}

// ----- Exceptions ----------------------------------------------------------

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low";
}

// ----- Operator<< ----------------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}
