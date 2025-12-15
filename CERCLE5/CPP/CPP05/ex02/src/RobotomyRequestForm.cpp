/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:09 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/13 00:36:52 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/*
**  50% success / 50% failure
**  Ici : alternance déterministe (1 fois sur 2) => conforme à "50% of the time".
**  Avantage : sortie stable et facile à expliquer en soutenance.
*/
static int	g_robot_toggle = 0;

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "BRRRRRRRRRRRRRR DRILLING NOISES..." << std::endl;
	if (g_robot_toggle++ % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy on " << this->_target << " failed" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName()
		<< ":\n\tsign-grade:\t" << a->getSignGrade()
		<< "\n\texec-grade:\t" << a->getExecGrade()
		<< "\n\tis signed:\t" << a->getIsSigned()
		<< std::endl;
	return (o);
}
