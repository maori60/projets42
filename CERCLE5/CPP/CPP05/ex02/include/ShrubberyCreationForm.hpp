/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:20 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:47:49 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	protected:
		virtual void	executeAction(void) const;

	public:
		// Orthodox Canonical Form
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();

		// Additional constructor
		ShrubberyCreationForm(std::string target);

		// Getter
		std::string	getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif
