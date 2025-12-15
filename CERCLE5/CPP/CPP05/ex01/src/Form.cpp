/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/12 23:52:59 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** Helper used to keep constructors clean and consistent.
** Ensures grades are always within [1..150].
*/
static void	checkFormGrades(int signGrade, int execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

/*
** Canonical form
*/

Form::Form(void)
	: _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
		_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkFormGrades(gradeToSign, gradeToExecute);
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		/*
		** _name, _gradeToSign and _gradeToExecute are const:
		** they cannot be reassigned after construction.
		*/
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(void)
{
}

/*
** Getters
*/

const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_isSigned);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/*
** Member functions
*/

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	/*
	** If already signed, do nothing (idempotent behavior).
	** Subject doesn't require an "AlreadySigned" exception.
	*/
	if (this->_isSigned)
		return ;
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

/*
** Exceptions
*/

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low");
}

/*
** Operator overload
*/

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form \"" << form.getName() << "\" (sign grade "
		<< form.getGradeToSign() << ", exec grade "
		<< form.getGradeToExecute() << ", signed: "
		<< (form.isSigned() ? "yes" : "no") << ")";
	return (os);
}
