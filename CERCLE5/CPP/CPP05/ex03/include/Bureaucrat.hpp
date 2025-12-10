#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class AForm;

class Bureaucrat
{
public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);

	// Getters
	const std::string	&getName() const;
	int					getGrade() const;

	// Grade modification
	void	incrementGrade();
	void	decrementGrade();

	// Interaction with forms
	void	signForm(AForm &form) const;
	void	executeForm(AForm const &form) const;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;

	void	checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif
