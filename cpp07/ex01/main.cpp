#include "iter.hpp"

int	main()
{
	int			a[5] = {0, 1, 2, 3, 4};
	double		b[5] = {0.0, 1.1, 2.2, 3.3, 4.4};
	char		c[5] = "test";
	const char	d[5] = "test";

	std::cout << "int test: " << std::endl;
	iter(a, 5, incr);
	iter(a, 5, print);
	std::cout << "double test: " << std::endl;
	iter(b, 5, incr);
	iter(b, 5, print);
	std::cout << "char test: " << std::endl;
	iter(c, 5, incr);
	iter(c, 5, print);
	std::cout << "const char test: " << std::endl;
	iter(d, 5, print);
	return 0;
}