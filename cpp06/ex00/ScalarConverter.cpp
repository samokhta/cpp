#include "ScalarConverter.hpp"
#include <cmath>
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string s)
{
	double	nbr;
	char	*ptr = NULL;

	if (s.length() == 1 && !isdigit(s.at(0)))
		nbr = static_cast<double>(s.at(0));
	else
		nbr = strtod(s.c_str(), &ptr);
	if (ptr && *ptr != 'f' && *ptr != '\0')
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (std::isnan(nbr) || std::isinf(nbr))
		std::cout << "Impossible" << std::endl;
	else if (isprint(static_cast<char>(nbr)))
		std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (std::isnan(nbr) || nbr > INT_MAX || nbr < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;

	std::cout << "float: ";
	std::cout << static_cast<float>(nbr);
	if (nbr - static_cast<int>(nbr) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: ";
	std::cout << nbr;
	if (nbr - static_cast<int>(nbr) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}
