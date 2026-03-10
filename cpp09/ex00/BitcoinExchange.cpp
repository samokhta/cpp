#include "BitcoinExchange.hpp"

//Functions
void	Database::parseDatabase()
{
	std::string		line;
	std::string		date;
	std::string		rate;
	std::ifstream	file("data.csv");

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
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

void	Database::parseInput(char *file)
{

}

const std::map<std::string, double>	&Database::getDatabase() const { return _database; }

//OCF

Database::Database() {}
Database::~Database() {}

Database::Database(const Database& other) : _database(other._database) {}

Database	&Database::operator=(const Database& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}
