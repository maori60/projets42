#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	// Orthodox Canonical Form
	Intern();
	Intern(Intern const &other);
	~Intern();
	Intern &operator=(Intern const &other);

	AForm	*makeForm(std::string const &formName, std::string const &target);

private:
	typedef AForm *(*t_creator)(std::string const &target);
	static AForm	*createShrubbery(std::string const &target);
	static AForm	*createRobotomy(std::string const &target);
	static AForm	*createPresidential(std::string const &target);
};

#endif
