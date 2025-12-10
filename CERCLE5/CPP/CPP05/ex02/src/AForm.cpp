/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:52:02 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:48:28 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"),
	_is_signed(false), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	std::cout << "AForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

AForm::AForm(int sign_grade, int exec_grade): _name("default"),
	_is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw (AForm::GradeTooLowException());
	else if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(const std::string name): _name(name),
	_is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getSignGrade() <<
	" and execution-grade of " << this->getExecGrade() << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade):
	_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	if (this->_sign_grade > 150 || this->_exec_grade > 150)
		throw (AForm::GradeTooLowException());
	else if (this->_sign_grade < 1 || this->_exec_grade < 1)
		throw (AForm::GradeTooHighException());
}

// Deconstructor
AForm::~AForm()
{
	std::cout << "AForm Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	// _name, _sign_grade, _exec_grade sont const -> pas assignables
	this->_is_signed = src.getIsSignedBool();
	return (*this);
}

// Public Methods
void	AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw (AForm::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
	{
		this->_is_signed = true;
		std::cout << this->getName() << " was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " is already signed" << std::endl;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSignedBool() == false)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (AForm::GradeTooLowException());
	this->executeAction();
}

// Getter
const std::string	AForm::getName(void) const
{
	return (this->_name);
}

const std::string	AForm::getIsSigned(void) const
{
	if (this->_is_signed)
		return ("✓ true");
	return ("✗ false");
}

bool	AForm::getIsSignedBool(void) const
{
	return (this->_is_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_exec_grade);
}

// Exceptions
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
}

// ostream Overload
std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}
