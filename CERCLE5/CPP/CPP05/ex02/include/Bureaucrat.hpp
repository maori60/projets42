/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:42:50 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:47:28 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm; // forward declaration

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		// Additional constructors
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(int grade);

		// Getters
		const std::string	getName(void) const;
		int					getGrade(void) const;

		// Setters
		void				setGrade(int grade);

		// Public methods
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(AForm &form);
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
