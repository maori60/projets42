#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
	// Orthodox Canonical Form
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	// Overridden execute
	virtual void	execute(Bureaucrat const &executor) const;

	// Helper for Intern
	static AForm	*create(std::string const &target);

private:
	std::string	_target;
};

#endif
