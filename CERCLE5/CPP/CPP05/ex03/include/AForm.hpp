#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
public:
	// Orthodox Canonical Form
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	AForm(AForm const &other);
	virtual ~AForm();
	AForm &operator=(AForm const &other);

	// Getters
	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	// Core methods
	void				beSigned(Bureaucrat const &bureaucrat);
	virtual void		execute(Bureaucrat const &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

protected:
	void	checkExecutable(Bureaucrat const &executor) const;

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

	void	checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif
