/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:20 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/13 00:37:05 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: AForm("ShrubberyCreationForm", 145, 137), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	outfile((this->_target + "_shrubbery").c_str());

	if (!outfile)
		return ;

	for (int i = 0; i < 5; i++)
	{
		outfile
			<< "         v" << std::endl
			<< "        >X<" << std::endl
			<< "         A" << std::endl
			<< "        d$b" << std::endl
			<< "      .d\\$$b." << std::endl
			<< "    .d$i$$\\$$b." << std::endl
			<< "       d$$@b" << std::endl
			<< "      d\\$$$ib" << std::endl
			<< "    .d$$$\\$$$b" << std::endl
			<< "  .d$$@$$$$\\$$ib." << std::endl
			<< "      d$$i$$b" << std::endl
			<< "     d\\$$$$@$b" << std::endl
			<< "  .d$@$$\\$$$$$@b." << std::endl
			<< ".d$$$$i$$$\\$$$$$$b." << std::endl
			<< "        ###" << std::endl
			<< "        ###" << std::endl
			<< "        ###" << std::endl
			<< std::endl;
	}
	outfile.close();
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName()
		<< ":\n\tsign-grade:\t" << a->getSignGrade()
		<< "\n\texec-grade:\t" << a->getExecGrade()
		<< "\n\tis signed:\t" << a->getIsSigned()
		<< std::endl;
	return (o);
}
