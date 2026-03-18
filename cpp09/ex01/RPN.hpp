#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <list>
#include <exception>
#include <stdexcept>
#include <cctype>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN &operator=(const RPN& other);
		~RPN();

		int	evaluate(const std::string& input) const;
	private:
		bool	checkSyntax(const std::string& input) const;
};

#endif