#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	btc;

	if (argc != 2)
	{
		std::cerr << "Usage: ./btc input.txt" << std::endl;
		return 1;
	}
	btc.parseDatabase();
	btc.processInput(argv[1]);
	return 0;
}