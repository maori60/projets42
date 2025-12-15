#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	protected:
		// action spécifique à chaque Form concrète
		virtual void		executeAction(void) const = 0;

	public:
		// Orthodox Canonical Form
		AForm(void);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm(void);

		// Constructors
		AForm(const std::string &name, int sign_grade, int exec_grade);

		// Getters
		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		// Public methods
		void				beSigned(Bureaucrat const &signer);
		void				execute(Bureaucrat const &executor) const;

		// Exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif
