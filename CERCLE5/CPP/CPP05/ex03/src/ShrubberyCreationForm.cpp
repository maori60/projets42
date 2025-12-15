#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);

	std::ofstream	out((_target + "_shrubbery").c_str());
	if (!out)
		throw std::runtime_error("could not create shrubbery file");

	out << "      /\\      \n";
	out << "     /\\*\\     \n";
	out << "    /\\O\\*\\    \n";
	out << "   /*/\\/\\/\\   \n";
	out << "  /\\O\\/\\*\\/\\  \n";
	out << " /\\*\\/\\*\\/\\/\\ \n";
	out << "/\\O\\/\\/*/\\/O/\\\n";
	out << "      ||      \n";
	out << "      ||      \n";
}

AForm	*ShrubberyCreationForm::create(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
