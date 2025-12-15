/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:00 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/13 00:42:51 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
	: AForm("PresidentialPardonForm", 25, 5), _target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "Form " << a->getName()
		<< ":\n\tsign-grade:\t" << a->getSignGrade()
		<< "\n\texec-grade:\t" << a->getExecGrade()
		<< "\n\tis signed:\t" << a->getIsSigned()
		<< std::endl;
	return (o);
}
