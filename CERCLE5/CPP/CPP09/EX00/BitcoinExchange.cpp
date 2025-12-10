/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:42:20 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 19:59:43 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/*                     CANONICAL FORM & CONSTRUCTOR                           */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange()
{
	// Le sujet impose d’utiliser la base data.csv fournie
	_readDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_quotes = other._quotes;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

/* ************************************************************************** */
/*                              PUBLIC METHOD                                 */
/* ************************************************************************** */

void BitcoinExchange::execute(const char *inputFile) const
{
	std::ifstream in(inputFile);
	if (!in.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	// Lecture de l’en-tête "date | value" (on l’ignore, même si mauvais)
	if (!std::getline(in, line))
	{
		// fichier vide : rien à faire
		return;
	}

	while (std::getline(in, line))
	{
		if (line.empty())
			continue;

		std::string::size_type pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			// Pas de séparateur ⇒ mauvais format
			std::cout << "Error: bad input => " << _trim(line) << std::endl;
			continue;
		}

		std::string date  = _trim(line.substr(0, pipePos));
		std::string value = _trim(line.substr(pipePos + 1));

		if (!_isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		double number;
		if (!_stringToDouble(value, number))
		{
			// Valeur non numérique
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (number < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (number > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		_printExchange(date, number);
	}
}

/* ************************************************************************** */
/*                          PRIVATE : DATABASE                                */
/* ************************************************************************** */

void BitcoinExchange::_readDatabase(const std::string &filename)
{
	std::ifstream db(filename.c_str());
	if (!db.is_open())
		throw std::runtime_error("Error: could not open database.");

	std::string line;

	// Première ligne : "date,exchange_rate"
	if (!std::getline(db, line))
		throw std::runtime_error("Error: empty database.");

	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: bad database format.");

	while (std::getline(db, line))
	{
		if (line.empty())
			continue;

		std::string::size_type commaPos = line.find(',');
		if (commaPos == std::string::npos)
			throw std::runtime_error("Error: bad database line: " + line);

		std::string date  = line.substr(0, commaPos);
		std::string value = line.substr(commaPos + 1);

		date  = _trim(date);
		value = _trim(value);

		if (!_isValidDate(date))
			throw std::runtime_error("Error: bad database date: " + date);

		double rate;
		if (!_stringToDouble(value, rate))
			throw std::runtime_error("Error: bad database rate: " + value);

		_quotes[date] = rate;
	}
}

/* ************************************************************************** */
/*                        PRIVATE : PARSING / UTILS                           */
/* ************************************************************************** */

std::string BitcoinExchange::_trim(const std::string &s)
{
	std::string::size_type start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		start++;

	std::string::size_type end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;

	return s.substr(start, end - start);
}

bool BitcoinExchange::_stringToDouble(const std::string &s, double &value)
{
	std::istringstream iss(s);
	iss >> value;
	if (iss.fail() || !iss.eof())
		return false;
	return true;
}

bool BitcoinExchange::_isValidDay(int year, int month, int day)
{
	if (day <= 0)
		return false;

	int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int dim = daysInMonth[month - 1];

	// gestion des années bissextiles pour février
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (leap)
			dim = 29;
	}
	return (day <= dim);
}

bool BitcoinExchange::_isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (!_isValidDay(year, month, day))
		return false;

	return true;
}

/* ************************************************************************** */
/*                  PRIVATE : PRINT RESULT WITH CLOSEST DATE                  */
/* ************************************************************************** */

void BitcoinExchange::_printExchange(const std::string &date, double value) const
{
	// Recherche de la date exacte ou de la date inférieure la plus proche
	std::map<std::string, double>::const_iterator it = _quotes.lower_bound(date);

	if (it == _quotes.end())
	{
		// Toutes les dates de la DB sont < date ⇒ on prend la dernière
		--it;
	}
	else if (it->first != date)
	{
		// lower_bound renvoie le premier élément > date
		if (it == _quotes.begin())
		{
			// Il n’existe aucune date inférieure ⇒ cas extrême, on ne traite pas
			std::cout << "Error: bad input => " << date << std::endl;
			return;
		}
		--it; // on prend la date immédiatement inférieure
	}

	double result = value * it->second;
	std::cout << date << " => " << value << " = " << result << std::endl;
}
