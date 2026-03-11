#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_database;

		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange	&operator=(const BitcoinExchange& other);

		bool	isValidDate(std::string& date) const;
		bool	isValidNumber(std::string& number) const;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void	parseDatabase();
		void	processInput(char *filename) const;
		const	std::map<std::string, double>	&getDatabase() const;
};

#endif