#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN &RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool	RPN::checkSyntax(const std::string& input) const
{
	char	c;

	if (input.size() < 2)
		return false;
	for (size_t i = 0; i < input.size(); i++)
	{
		c = input[i];
		if (i % 2 == 1 && c != ' ')
			return false;
		if (i % 2 == 0)
		{
			if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
				return false;
		}
	}
	return true;
}

int	RPN::evaluate(const std::string& input) const
{
	char	c;
	int		a;
	int		b;
	std::stack<int, std::list<int> >	st;

	if (input.size() == 1 && isdigit(input[0]))
		return (input[0] - '0');
	if (!checkSyntax(input))
		throw std::runtime_error("syntax");
	for (size_t i = 0; i < input.size(); i++)
	{
		c = input[i];
		if (i % 2 == 1)
			continue;
		if (isdigit(c))
		{
			st.push(c - '0');
			continue;
		}
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (st.size() < 2)
				throw std::runtime_error("syntax (not enough operands)");
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			if (c == '+')
				st.push(a + b);
			if (c == '-')
				st.push(a - b);
			if (c == '*')
				st.push(a * b);
			if (c == '/')
			{
				if (b == 0)
					throw std::runtime_error("dividing by 0");
				st.push(a / b);
			}
		}
	}
	if (st.size() != 1)
		throw std::runtime_error("syntax (too many operands)");
	return st.top();
}