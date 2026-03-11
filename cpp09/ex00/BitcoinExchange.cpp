#include "BitcoinExchange.hpp"

//Functions

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	std::string	cpy;
	size_t	year;
	size_t	month;
	size_t	day;
	size_t	maxDay;

	if (date[4] != '-' || date[7] != '-')
		return false;
	cpy = date.substr(0, 4);
	year = atoi(cpy.c_str());
	cpy = date.substr(5, 2);
	month = atoi(cpy.c_str());
	cpy = date.substr(8, 2);
	day = atoi(cpy.c_str());
	//std::cout << "DEBUG: " << year << " " << month << " " << day << std::endl;
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			maxDay = 31; break;
		case 4: case 6: case 9: case 11:
			maxDay = 30; break;
		case 2:
			maxDay = 29; break;
		default:
			return (false);
	}
	if (!year || !day)
		return false;
	if (year > 9999 || day > maxDay)
		return false;
	return true;
}

bool	BitcoinExchange::isValidAmount(const std::string& amount) const
{
	bool frac = false;

	for (size_t i = 0; i < amount.size(); i++)
	{
		if (amount[i] == '.')
		{
			if (frac)
				return false;
			frac = true;
		}
		else if (!isdigit(amount[i]))
		{
			if (i != 0 || amount[i] != '-')
				return false;
		}
	}
	return true;
}

double	BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator	it = _database.lower_bound(date);

	if (it == _database.end())
	{
		it--;
		return it->second;
	}
	if (it->first == date)
		return it->second;
	if (it == _database.begin())
		return it->second;
	it--;
	return it->second;
}

void	BitcoinExchange::exchange(const std::string& date, const double& amount) const
{
	double rate = getRate(date);
	double res = rate * amount;
	std::cout << date << " => " << amount << " = " << res << std::endl;
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
		amount = line.substr(13);
		//std::cout << "DEBUG:" << amount << std::endl;
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidAmount(amount))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (atof(amount.c_str()) < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (atof(amount.c_str()) > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		exchange(date, atof(amount.c_str()));
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
