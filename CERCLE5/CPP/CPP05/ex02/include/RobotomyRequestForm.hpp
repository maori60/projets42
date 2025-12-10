/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:09 by tblaase           #+#    #+#             */
/*   Updated: 2025/12/03 12:48:00 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	protected:
		virtual void	executeAction(void) const;

	public:
		// Orthodox Canonical Form
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm();

		// Additional constructor
		RobotomyRequestForm(std::string target);

		// Getter
		std::string	getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif
