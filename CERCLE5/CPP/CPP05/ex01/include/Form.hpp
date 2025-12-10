/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/12/03 12:20:44 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form();
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string   &getName(void) const;
        bool                isSigned(void) const;
        int                 getGradeToSign(void) const;
        int                 getGradeToExecute(void) const;

        void                beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
