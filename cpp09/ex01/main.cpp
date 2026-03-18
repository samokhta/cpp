#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2)
	{
		std::cerr << "argc Error" << std::endl;
		return 1;
	}
	try
	{
		int result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}