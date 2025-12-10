/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:32:32 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 20:13:10 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>  // std::stringstream
#include <cctype>   // std::isdigit

/* ************************************************************************** */
/*                           CANONICAL FORM                                   */
/* ************************************************************************** */

RPN::RPN()
{
}

RPN::RPN(const std::string &expression)
{
	_parseExpression(expression);
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

/* ************************************************************************** */
/*                                PUBLIC                                      */
/* ************************************************************************** */

int	RPN::getResult() const
{
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}

/* ************************************************************************** */
/*                               PRIVATE                                      */
/* ************************************************************************** */

void RPN::_parseExpression(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string       token;

	// operator>> saute automatiquement les espaces multiples
	while (ss >> token)
	{
		_processToken(token);
	}
}

void RPN::_processToken(const std::string &token)
{
	if (_isDigitToken(token))
	{
		// un seul chiffre entre '0' et '9'
		int value = token[0] - '0';
		_stack.push(value);
	}
	else if (_isOperatorToken(token))
	{
		_applyOperator(token[0]);
	}
	else
	{
		// tout le reste (parenthèses, mots, etc.) => erreur
		throw std::runtime_error("Error");
	}
}

void RPN::_applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();

	long result = 0;

	switch (op)
	{
		case '+':
			result = static_cast<long>(left) + static_cast<long>(right);
			break;
		case '-':
			result = static_cast<long>(left) - static_cast<long>(right);
			break;
		case '*':
			result = static_cast<long>(left) * static_cast<long>(right);
			break;
		case '/':
			if (right == 0)
				throw std::runtime_error("Error");
			result = left / right;
			break;
		default:
			throw std::runtime_error("Error");
	}
	// On reste en int pour coller au sujet (petits nombres en entrée)
	_stack.push(static_cast<int>(result));
}

/* ************************************************************************** */
/*                          STATIC HELPERS                                    */
/* ************************************************************************** */

bool RPN::_isDigitToken(const std::string &token)
{
	// un seul caractère, compris entre '0' et '9'
	return (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])));
}

bool RPN::_isOperatorToken(const std::string &token)
{
	if (token.size() != 1)
		return false;
	char c = token[0];
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
