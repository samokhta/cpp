#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>

class Database
{
	private:
		std::map<std::string, double>	_database;

	public:
		Database();
		Database(const Database& other);
		Database	&operator=(const Database& other);
		~Database();
		void	parseDatabase();
		void	parseInput(char *file);
		const	std::map<std::string, double>	&getDatabase() const;
};

#endif