/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:00 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:48:08 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	protected:
		virtual void	executeAction(void) const;

	public:
		// Orthodox Canonical Form
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm();

		// Additional constructor
		PresidentialPardonForm(std::string target);

		// Getter
		std::string	getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif
