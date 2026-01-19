#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other) {}
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string s)
{
	double	nbr; //on utilise double pour eviter les downcasts puisque c le type le plus complexe
	size_t	idx; //pour passer dans std::stod

	//check si s est un char non numerique(ex: 'a', '@', '!', etc.), si oui cast le dans nbr
	//sinon convertis s dans double avec std::stod et verifie que l'input est bien valide
}