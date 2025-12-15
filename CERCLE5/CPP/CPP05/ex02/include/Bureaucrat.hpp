#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		void				_checkGrade(int grade) const;

	public:
		// Orthodox Canonical Form
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat(void);

		// Constructors
		Bureaucrat(const std::string &name, int grade);

		// Getters
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		// Grade manipulation
		void				incrementGrade(void);
		void				decrementGrade(void);

		// Form actions
		void				signForm(AForm &form) const;
		void				executeForm(AForm const &form) const;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b);

#endif
