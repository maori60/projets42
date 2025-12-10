#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	// Orthodox Canonical Form
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	// Overridden execute
	virtual void	execute(Bureaucrat const &executor) const;

	// Helper for Intern
	static AForm	*create(std::string const &target);

private:
	std::string	_target;
};

#endif
