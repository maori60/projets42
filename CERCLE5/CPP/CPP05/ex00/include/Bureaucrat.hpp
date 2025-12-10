#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	public:
		// Orthodox Canonical Form
		Bureaucrat();                             // grade 150, name "Default"
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(int grade);                   // name "Default"
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Getters
		const std::string &getName() const;
		int                getGrade() const;

		// Grade manipulation
		void incrementGrade(); // 2 -> 1 (grade--)
		void decrementGrade(); // 2 -> 3 (grade++)

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
		const std::string _name;
		int               _grade;

		void _checkGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
