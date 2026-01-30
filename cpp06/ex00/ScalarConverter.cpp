#include "ScalarConverter.hpp"
//TODO : remove .0/.0f for inf/nan
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static Type	findType(std::string s)
{
	if (s.empty())
		return ERROR;

	// char
	if (s.size() == 1 && !std::isdigit(s[0]))
		return CHAR;

	// int
	char* end;
	long val = strtol(s.c_str(), &end, 10);
	if (*end == '\0' && !(val < INT_MIN || val > INT_MAX))
		return INT;

	// float
	strtof(s.c_str(), &end);
	if (end != s.c_str() && *end == 'f' && *(end + 1) == '\0')
		return FLOAT;

	// double
	strtod(s.c_str(), &end);
	if (end != s.c_str() && *end == '\0')
		return DOUBLE;

	return ERROR;
}

static void	printType(Type inputType)
{
	switch (inputType)
	{
		case CHAR:
			std::cout << "input type: char" << std::endl;
			break ;
		case INT:
			std::cout << "input type: int" << std::endl;
			break ;
		case FLOAT:
			std::cout << "input type: float" << std::endl;
			break ;
		case DOUBLE:
			std::cout << "input type: double" << std::endl;
			break ;
		case ERROR:
			std::cout << "Invalid input" << std::endl;
			break ;
		break;
	}
}
static void	charConvert(std::string s)
{
	char	c = s[0];

	std::cout << "char: \'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	intConvert(std::string s)
{
	int	i = strtol(s.c_str(), NULL, 10);

	if (isprint(static_cast<char>(i)))
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: Impossible (Out of Bounds)" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void	floatConvert(std::string s)
{
	float	f = strtof(s.c_str(), NULL);

	if (std::isnan(f) || std::isinf(f))
		std::cout << "char: Impossible" << std::endl;
	else if (isprint(static_cast<char>(f)))
		std::cout << "char: \'" << static_cast<char>(f) << "\'" << std::endl;
	else if (static_cast<int>(f) < 0 || static_cast<int>(f) > 127)
		std::cout << "char: Impossible (Out of Bounds)" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (std::isnan(f) || f > INT_MAX || f <= INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

static void	doubleConvert(std::string s)
{
	double	d = strtod(s.c_str(), NULL);

	if (std::isnan(d) || std::isinf(d))
		std::cout << "char: Impossible" << std::endl;
	else if (isprint(static_cast<char>(d)))
		std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;
	else if (static_cast<int>(d) < 0 || static_cast<int>(d) > 127)
		std::cout << "char: Impossible (Out of Bounds)" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (std::isnan(d) || d > INT_MAX || d <= INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convert(std::string s)
{
	Type	inputType = findType(s);

	printType(inputType);
	switch (inputType)
	{
		case CHAR:
			charConvert(s);
			break;
		case INT:
			intConvert(s);
			break;
		case FLOAT:
			floatConvert(s);
			break;
		case DOUBLE:
			doubleConvert(s);
			break;
		case ERROR:
			break;
	}
}
