/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:42:20 by cgodecke          #+#    #+#             */
/*   Updated: 2025/12/10 19:59:17 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <stdexcept>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// Lance le traitement du fichier d’entrée (input.txt)
		void execute(const char *inputFile) const;

	private:
		std::map<std::string, double> _quotes;

		// Chargement de data.csv
		void _readDatabase(const std::string &filename);

		// Parsing / validation
		static std::string _trim(const std::string &s);
		static bool        _isValidDate(const std::string &date);
		static bool        _stringToDouble(const std::string &s, double &value);

		// Calcul et affichage du résultat
		void _printExchange(const std::string &date, double value) const;

		// Utilitaire pour validation des jours par mois
		static bool _isValidDay(int year, int month, int day);
};

#endif
