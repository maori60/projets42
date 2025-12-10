#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors / Destructor

AForm::AForm()
	: _name("DefaultForm"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	checkGrade(signGrade);
	checkGrade(execGrade);
}

AForm::AForm(AForm const &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _signGrade(other._signGrade),
	  _execGrade(other._execGrade)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

// Private

void	AForm::checkGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Getters

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

// Core methods

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

// Exceptions

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

// Operator <<

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	os << "Form \"" << f.getName() << "\""
	   << " [sign grade " << f.getSignGrade()
	   << ", exec grade " << f.getExecGrade()
	   << ", signed: " << (f.getIsSigned() ? "yes" : "no") << "]";
	return (os);
}
