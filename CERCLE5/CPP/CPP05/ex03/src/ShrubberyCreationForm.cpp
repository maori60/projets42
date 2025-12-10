#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

// Constructors / Destructor

ShrubberyCreationForm::ShrubberyCreationForm()
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// execute

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);

	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error("Failed to open shrubbery file");

	ofs << "      /\\      \n";
	ofs << "     /\\*\\     \n";
	ofs << "    /\\O\\*\\    \n";
	ofs << "   /*/\\/\\/\\   \n";
	ofs << "  /\\O\\/\\*\\/\\  \n";
	ofs << " /\\*\\/\\*\\/\\/\\ \n";
	ofs << "/\\O\\/\\/*/\\/O/\\\n";
	ofs << "      ||      \n";
	ofs << "      ||      \n";
}

// Helper for Intern

AForm	*ShrubberyCreationForm::create(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
