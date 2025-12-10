/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:32:32 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 20:12:59 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>

class RPN
{
	public:
		RPN();
		RPN(const std::string &expression);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	getResult() const;

	private:
		std::stack<int> _stack;

		void _parseExpression(const std::string &expression);
		void _processToken(const std::string &token);
		void _applyOperator(char op);

		static bool _isDigitToken(const std::string &token);
		static bool _isOperatorToken(const std::string &token);
};

#endif
