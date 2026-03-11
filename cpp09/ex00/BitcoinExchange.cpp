#include "BitcoinExchange.hpp"

//Functions

bool	BitcoinExchange::isValidDate(std::string& date) const
{

}

bool	BitcoinExchange::isValidNumber(std::string& number) const
{

}

void	BitcoinExchange::parseDatabase()
{
	std::string		line;
	std::string		date;
	std::string		rate;
	std::ifstream	file("data.csv");

	if (!file.is_open())
	{
		std::cerr << "parseDatabase error: could not open database file" << std::endl;
		return ;
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		date = line.substr(0, 10);
		rate = line.substr(11);
		_database[date] = atof(rate.c_str());
	}
	file.close();
}

void	BitcoinExchange::processInput(char *filename) const
{
	size_t			sep;
	std::string		line;
	std::string		date;
	std::string		amount;
	std::ifstream	file(filename);
	if (!file.is_open())
	{
		std::cerr << "processInput error: could not open file" << std::endl;
		return ;
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		

		date = line.substr(0, 10);
		amount = line.substr(14);

	}
	file.close();
}

const std::map<std::string, double>	&BitcoinExchange::getDatabase() const { return _database; }

//OCF

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}
