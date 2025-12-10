#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	// Orthodox Canonical Form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

	// Overridden execute
	virtual void	execute(Bureaucrat const &executor) const;

	// Helper for Intern
	static AForm	*create(std::string const &target);

private:
	std::string	_target;
};

#endif
