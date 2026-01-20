#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <climits>
# include <cmath>

	class ScalarConverter
	{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter	&operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void	convert(std::string s);
	};

#endif