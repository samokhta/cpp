#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

//exceptions: -inff/+inff/nanf, -inf/+inf/nan
//	double	nbr; //on utilise double pour eviter les downcasts puisque c le type le plus complexe
//	size_t	idx; //pour passer dans std::stod
//	int		type;

//check si s est un char non numerique(ex: 'a', '@', '!', etc.), si oui cast le dans nbr
//sinon convertis s dans double avec std::stod et verifie que l'input est bien valide
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
}