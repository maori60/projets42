/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/03 12:21:08 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
**  Canonical form
*/

Form::Form(void)
    : _name("default"), _isSigned(false),
      _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

Form::~Form(void)
{
}

/*
**  Getters
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
**  Member functions
*/

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

/*
**  Exceptions
*/

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Form grade is too low");
}

/*
**  Operator overload
*/

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form \"" << form.getName() << "\" (sign grade "
       << form.getGradeToSign() << ", exec grade "
       << form.getGradeToExecute() << ", signed: "
       << (form.isSigned() ? "yes" : "no") << ")";
    return (os);
}
