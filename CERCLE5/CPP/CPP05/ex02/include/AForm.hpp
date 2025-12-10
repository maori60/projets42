/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:52:02 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:47:38 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		// Fonction d'action purement virtuelle => rend la classe abstraite
		virtual void		executeAction(void) const = 0;

	public:
		// Orthodox Canonical Form
		AForm(void);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		// Additional constructors
		AForm(const std::string name);
		AForm(int sign_grade, int exec_grade);
		AForm(const std::string name, int sign_grade, int exec_grade);

		// Getters
		const std::string	getName(void) const;
		const std::string	getIsSigned(void) const;
		bool				getIsSignedBool(void) const;
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

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif
