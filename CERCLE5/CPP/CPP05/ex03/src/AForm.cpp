#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* =========================
   Canonical form
   ========================= */

AForm::AForm(void)
	: _name("AForm"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (_signGrade > 150 || _execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

AForm::~AForm(void)
{
}

AForm	&AForm::operator=(AForm const &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

/* =========================
   Core behavior
   ========================= */

void	AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > _signGrade)
		throw (AForm::GradeTooLowException());
	_isSigned = true;
}

void	AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > _execGrade)
		throw (AForm::GradeTooLowException());
}

/*
** NOTE:
** Ton header n’a pas executeAction().
** Donc execute() ici fait UNIQUEMENT les checks.
** Les classes dérivées (Shrubbery/Robotomy/Presidential) doivent ensuite
** override execute() et appeler checkExecutable() puis faire leur action.
*/
void	AForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);
}

/* =========================
   Getters
   ========================= */

const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

/* =========================
   Exceptions
   ========================= */

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm grade too low");
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm grade too high");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm not signed");
}

/* =========================
   ostream overload
   ========================= */

std::ostream	&operator<<(std::ostream &o, AForm const &f)
{
	o << f.getName()
	  << " (sign grade " << f.getSignGrade()
	  << ", exec grade " << f.getExecGrade()
	  << ", signed: " << (f.getIsSigned() ? "yes" : "no") << ")";
	return (o);
}
