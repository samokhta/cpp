#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <exception>
#include <cctype>

class RPN
{
public:
	RPN();
	RPN(const RPN& other);
	RPN &operator=(const RPN& other);
	~RPN();

	int	evaluate(const std::string& input) const;
};

#endif