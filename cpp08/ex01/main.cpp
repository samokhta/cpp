#include "Span.hpp"

int	main()
{
	Span sp1 = Span(5);

	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);

	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
	std::cout << std::endl;

	/**********************************************************************************/

	try
	{
		Span	sp2(0);
		sp2.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	std::cout << std::endl;

	/**********************************************************************************/

	Span	sp3(20);

	try
	{
		sp3.addNumberRange(1, 15);
		sp3.addNumberRange(1, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
	sp3.printSpan();
	std::cout << std::endl;

	/**********************************************************************************/

	Span				sp4(20);
	std::vector<int>	vect;

	for (size_t i = 1; i <= 20; i++)
		vect.push_back(i);
	sp4.addNumberRange(vect.begin(), vect.end());
	sp4.printSpan();
	std::cout << std::endl;

	/**********************************************************************************/
/*
	Span	sp5(15000);

	sp5.addNumberRange(1, 15000);
	sp5.printSpan();
	std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
*/
	return 0;
}